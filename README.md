<h1 align="center"><img title="The Long Night Is Coming" src="https://raw.githubusercontent.com/FandomGold/fango-wallet/master/src/images/splash.png" width="1800" height="500" ><img/></h1>

Binaries are made available by Fandom Gold Project community members. If you are able to compile on your operating system, please consider helping others by adding to the release. Also if your OS is available, please consider donating to the community member who made it possible. For up to date info & tons of ways to tip or earn Fango - [join us in our discord server(http://discord.fandom.gold)].


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
cmake -DCMAKE_PREFIX_PATH:STRING=<Qt path/Qt version/clang_64/> 
```
Additional build step to bundle static libraries with app package:
```
<Qt path/Qt version/clang_64/bin/macdeployqt> <path to your project/build/fango-wallet.app
```
