<h1 align="center"><img title="The Long Night Is Coming" src="https://raw.githubusercontent.com/FandomGold/XFG-data/master/images/F8851747-376B-4E59-9C8E-7C25BF753C59.jpeg" width="1800" height="500" ><img/></h1>

Binaries are made available by Fandom Gold Society and/or Fango XFG community members. If you are able to compile on your operating system, please consider helping others by adding to the release. Also if your OS is available, please consider donating to the community member who made it possible. For up to date info & tons of ways to earn or tip Fango - [join us in our discord](http://discord.fandom.gold).


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
