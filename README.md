# order-by

order the records of one file (or array) by the order of keys in another

```
npm install -g order-by
```

## Usage

``` bash

% cat x 
rs4477212       AA
rs3094315       AA
rs3131972       GG
rs12124819      AA
rs11240777      GG

# we'll sort these according to their order in the second file

% cat y
rs11240777
rs12124819
rs3094315
rs3131972
rs4477212

# boom

% order-by x 1 y                                                                        
rs11240777      GG
rs12124819      AA
rs3094315       AA
rs3131972       GG
rs4477212       AA

```

## License

MIT
