<h1 align="center"><img height="400px" width="800px" title="The Long Night Is Coming" src="https://github.com/usexfg/XFG-wallet/blob/fe5a16c78f4eae23907a8e0b3ae794ea96c6f467/src/images/splash.png"><img/></h1>

# Be Your Own Private Bank
Use your PC or laptop's CPU power to mine Fango and start making money while you sleep.

XFG wallet includes built-in solo & pool mining options.

See [Releases](https://github.com/FandomGold/XFG-wallet/releases) for pre-built binaries


### Build From Source 

### instructions for *nix users

**1. Clone wallet sources**

```
git clone --recursive https://github.com/FandomGold/xfg-wallet
```

```
cd xfg-wallet
```

**2. Build**

```
mkdir build && cd build && cmake .. && make
```

**3. Running XFG Wallet**

Resulting software application will be found in release folder

```
cd build/release
```

Allow filename *Fango-Wallet* to operate as an executable program or run console command:

```
./Fango-Wallet
```

-------------------------------------
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

Need any kind of help or for more info about Fango- plus tons of more ways to use & earn $XFG - join our ever-growing grassroots community of XFG Holders, miners, & users in [FANGO's official discord server](https://discord.gg/2wQAgAqdUM).

