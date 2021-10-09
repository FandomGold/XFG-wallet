<h1 align="center"><img title="The Long Night Is Coming" src="https://raw.githubusercontent.com/FandomGold/fango-wallet/master/src/images/splash.png"><img/></h1>

# Be Your Own Private Bank
XFG wallet includes built-in solo & pool options to mine Fango.

See [Release](https://github.com/FandomGold/fango-wallet/releases) section for pre-built binaries

For up to date info & tons of ways to tip or earn Fango - [join us in discord](http://discord.fandom.gold).

### Building on *nix

**1. Clone wallet sources**

```
git clone --recursive https://github.com/FandomGold/fango-wallet
```

```
cd fango-wallet
```

**2. Build**

```
mkdir build && cd build && cmake .. && make
```
### Build instructions for Mac
Same as *nix build instructions but cmake will likely need your qt path, so :
```
mkdir build && cd build
cmake -DCMAKE_PREFIX_PATH:STRING="/usr/local/Cellar/qt/<qt version>/ .."
make
```
Additional build step to bundle static libraries with app package:
```
/usr/local/Cellar/qt/<qt version>/bin/macdeployqt> <path to your project/build/fango-wallet.app
```
