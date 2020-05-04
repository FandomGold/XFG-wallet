<h1 align="center"><img title="The Long Night Is Coming" src="https://raw.githubusercontent.com/FandomGold/fango-wallet/master/src/images/splash.png" width="1800" height="500" ><img/></h1>

Binaries are made available by Fandom Gold Project community members. If you are able to compile on your operating system, please consider helping others by adding to the release. Also if your OS is available, please consider donating to the community member who made it possible. For more up to date info & tons of ways to earn fango via tips- come [join us](http://discord.fandom.gold) in our discord server.


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

-----------
Wallet Release History
=====
<h1 align="center"><img title="The Long Night Is Coming" src="https://github.com/aejontargaryen/DRGL-X/blob/master/images/DRGL/Splash_I%26F.png" width="1800" height="500" ><img/></h1>

<h1 align="center"><img title="The Long Night Is Coming" src="https://raw.githubusercontent.com/aejontargaryen/DRGL-X/master/images/DRGL/splash_Ironborne.png" width="1800" height="500" ><img/></h1>

<h1 align="center"><img title="The Long Night Is Coming" src="https://raw.githubusercontent.com/aejontargaryen/DRGL-X/master/images/DRGL/splash_Dacarys.png" width="1800" height="500" ><img/></h1>

<h1 align="center"><img title="The Long Night Is Coming" src="https://raw.githubusercontent.com/aejontargaryen/DRGL-X/master/images/DRGL/splash_OathKprII.png" width="1800" height="500" ><img/></h1>

<h1 align="center"><img title="The Long Night Is Coming" src="https://raw.githubusercontent.com/aejontargaryen/DRGL-X/master/images/DRGL/splash_OathKpr.png" width="1800" height="500" ><img/></h1>

<h1 align="center"><img title="The Long Night Is Coming" src="https://raw.githubusercontent.com/aejontargaryen/DRGL-X/master/images/DRGL/splash_131.png" width="1800" height="500" ><img/></h1>
