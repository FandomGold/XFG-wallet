// Copyright (c) 2011-2015 The Cryptonote developers
// Copyright (c) 2016 The Karbowanec developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <QFontDatabase>
#include "CurrencyAdapter.h"
#include "OverviewFrame.h"
#include "TransactionFrame.h"
#include "RecentTransactionsModel.h"
#include "WalletAdapter.h"
#include "PriceProvider.h"
#include "NodeAdapter.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QStringList>
#include <QUrl>

#include "ui_overviewframe.h"

namespace WalletGui {

class RecentTransactionsDelegate : public QStyledItemDelegate {
  Q_OBJECT

public:
  RecentTransactionsDelegate(QObject* _parent) : QStyledItemDelegate(_parent) {
  }

  ~RecentTransactionsDelegate() {
  }

  QWidget* createEditor(QWidget* _parent, const QStyleOptionViewItem& _option, const QModelIndex& _index) const Q_DECL_OVERRIDE {
    if (!_index.isValid()) {
      return nullptr;
    }

    return new TransactionFrame(_index, _parent);
  }

  QSize sizeHint(const QStyleOptionViewItem& _option, const QModelIndex& _index) const Q_DECL_OVERRIDE {
    return QSize(346, 64);
  }
};

OverviewFrame::OverviewFrame(QWidget* _parent) : QFrame(_parent), m_ui(new Ui::OverviewFrame), m_priceProvider(new PriceProvider(this)), m_transactionModel(new RecentTransactionsModel) {
  m_ui->setupUi(this);

  connect(&WalletAdapter::instance(), &WalletAdapter::walletActualBalanceUpdatedSignal, this, &OverviewFrame::updateActualBalance,
    Qt::QueuedConnection);
  connect(&WalletAdapter::instance(), &WalletAdapter::walletPendingBalanceUpdatedSignal, this, &OverviewFrame::updatePendingBalance,
    Qt::QueuedConnection);
  connect(&WalletAdapter::instance(), &WalletAdapter::walletCloseCompletedSignal, this, &OverviewFrame::reset,
    Qt::QueuedConnection);
  connect(m_transactionModel.data(), &QAbstractItemModel::rowsInserted, this, &OverviewFrame::transactionsInserted);
  connect(m_transactionModel.data(), &QAbstractItemModel::layoutChanged, this, &OverviewFrame::layoutChanged);
  /*connect(m_priceProvider, &PriceProvider::priceFoundSignal, this, &OverviewFrame::onPriceFound);*/


  m_ui->m_tickerLabel1->setText(CurrencyAdapter::instance().getCurrencyTicker().toUpper());
  m_ui->m_tickerLabel2->setText(CurrencyAdapter::instance().getCurrencyTicker().toUpper());
  m_ui->m_tickerLabel3->setText(CurrencyAdapter::instance().getCurrencyTicker().toUpper());

  m_ui->m_recentTransactionsView->setItemDelegate(new RecentTransactionsDelegate(this));
  m_ui->m_recentTransactionsView->setModel(m_transactionModel.data());
  reset();
}

OverviewFrame::~OverviewFrame() {
}

void OverviewFrame::transactionsInserted(const QModelIndex& _parent, int _first, int _last) {
  for (quint32 i = _first; i <= _last; ++i) {
    QModelIndex recentModelIndex = m_transactionModel->index(i, 0);
    m_ui->m_recentTransactionsView->openPersistentEditor(recentModelIndex);
  }
}

void OverviewFrame::layoutChanged() {
  for (quint32 i = 0; i <= m_transactionModel->rowCount(); ++i) {
    QModelIndex recent_index = m_transactionModel->index(i, 0);
    m_ui->m_recentTransactionsView->openPersistentEditor(recent_index);
  }
}

void OverviewFrame::updateActualBalance(quint64 _balance) {
  m_ui->m_actualBalanceLabel->setText(CurrencyAdapter::instance().formatAmount(_balance).remove(','));
  quint64 pendingBalance = WalletAdapter::instance().getPendingBalance();
  m_ui->m_totalBalanceLabel->setText(CurrencyAdapter::instance().formatAmount(_balance + pendingBalance).remove(','));
}

void OverviewFrame::updatePendingBalance(quint64 _balance) {
  m_ui->m_pendingBalanceLabel->setText(CurrencyAdapter::instance().formatAmount(_balance).remove(','));
  quint64 actualBalance = WalletAdapter::instance().getActualBalance();
  m_ui->m_totalBalanceLabel->setText(CurrencyAdapter::instance().formatAmount(_balance + actualBalance).remove(','));
}
/*
void OverviewFrame::onPriceFound(const QString& _usdxfg, const QString &_usdmarketcap, const QString &_usdvolume) {

  float total = 0;
  xfgusd = _usdxfg.toFloat();
  m_ui->m_xfgusd->setText("$" + _usdxfg);
  m_ui->m_marketCap->setText("$" + _usdmarketcap);
  m_ui->m_volume->setText("$" + _usdvolume);
  updatePortfolio();z
}

void OverviewFrame::updatePortfolio() {

  float total = 0;
  total = xfgusd * (float)OverviewFrame::totalBalance;
  m_ui->m_totalPortfolioLabelUSD->setText("TOTAL " + CurrencyAdapter::instance().formatAmount(OverviewFrame::totalBalance) +
  " XFG | " + CurrencyAdapter::instance().formatCurrencyAmount(total / 10000000) + " " + "USD");
}*/

void OverviewFrame::reset() {
  updateActualBalance(0);
  updatePendingBalance(0);
  /*m_priceProvider->getPrice();*/
}

}

#include "OverviewFrame.moc"
