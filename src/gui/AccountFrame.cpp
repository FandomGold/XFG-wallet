// Copyright (c) 2011-2015 The Cryptonote developers
// Copyright (c) 2016-2017 The Karbowanec developers
// Copyright (c) 2017-2021 The Fango developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <QClipboard>
#include <QTimer>
#include <QFontDatabase>
#include <QFont>
#include <QMovie>
#include "AccountFrame.h"
#include "WalletAdapter.h"
#include "CurrencyAdapter.h"

#include "ui_accountframe.h"

namespace WalletGui {

AccountFrame::AccountFrame(QWidget* _parent) : QFrame(_parent), m_ui(new Ui::AccountFrame),
  m_xfgMovie(new QMovie(this)){
  m_ui->setupUi(this);
  m_xfgMovie->setFileName(":images/xfgblx");
  m_xfgMovie->setScaledSize(QSize(80, 80));
  m_ui->m_xfgLabel->setMovie(m_xfgMovie);
  m_xfgMovie->start();
  connect(&WalletAdapter::instance(), &WalletAdapter::updateWalletAddressSignal, this, &AccountFrame::updateWalletAddress);
  connect(&WalletAdapter::instance(), &WalletAdapter::walletActualBalanceUpdatedSignal, this, &AccountFrame::updateWalletBalance,
    Qt::QueuedConnection);
  connect(&WalletAdapter::instance(), &WalletAdapter::walletCloseCompletedSignal, this, &AccountFrame::reset);
}

AccountFrame::~AccountFrame() {
}

void AccountFrame::updateWalletAddress(const QString& _address) {
  m_ui->m_addressLabel->setText(_address);
}

void AccountFrame::copyAddress() {
  QApplication::clipboard()->setText(m_ui->m_addressLabel->text());
  m_ui->addressStatusLabel->setText(tr("Copied to clipboard"));
  QTimer::singleShot(1500,this,SLOT(clearLabel()));
}

void AccountFrame::showQR() {
  Q_EMIT showQRcodeSignal();
}

void AccountFrame::clearLabel() {
m_ui->addressStatusLabel->setText(tr(""));
}

void AccountFrame::updateWalletBalance(quint64 _balance) {
  quint64 actualBalance = WalletAdapter::instance().getActualBalance();
  quint64 pendingBalance = WalletAdapter::instance().getPendingBalance();
  m_ui->totalBalance->setText(CurrencyAdapter::instance().formatAmount(actualBalance + pendingBalance).remove(','));
}

void AccountFrame::reset() {
  m_ui->m_addressLabel->clear();
  updateWalletBalance(0);
}

}
