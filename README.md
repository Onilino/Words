# Words
A simple program that find all french word from a file dictionnary, depending to the arguments given in parameter


___



## Manual

  + [C++ & dependencies](https://fr.cppreference.com/w/) (Standard Language)


___



## Description

Binary : ==words==
| Parametrer | Description |
| ------ | ----------- |
| `-h` `--help`| take a look to the usage |
| `-imin` | specify the minimum word's length |
| `-imax` | specify the maximum word's length |         

+ If you specify a ==_== charactere instead of a letter, the script will only find words matching with the letters given in parameters and this "void", with the **same** length as the number of 'letters' parameters.

#### Exemples
| In| Out |
| -- | --- |
| `./words L _ R _ E` |  ==LARGE== ==LARME== ==LIRIE== |
| `./words M _ R A _ E` | ==MIRAGE== ==MORALE== ==MURALE==  | 


___



# Execution

Just launch it with any IDE or by using 
```
$ make
$ ./words   letters['_'][...] [-imin length] [-imax length] [-h --help]
```
