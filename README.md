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

The method also works on objects, but must be called from javascript:

``` js
// we'd like to sort this by the order in b
var a = [{key:'one',value:'x'},
         {key:'two',value:'x'},
         {key:'two',value:'y'},
         {key:'three',value:'x'},
         {key:'wee',value:'y'},
         {key:'four',value:'x'}]

// our order
var b = ['four','two','three','one']

var orderBy = require('order-by')

// use the value of 'key' in a when sorting according to b
orderBy(a, 'key', b)
/*
[ { key: 'four', value: 'x' },
  { key: 'two', value: 'x' },
  { key: 'two', value: 'y' },
  { key: 'three', value: 'x' },
  { key: 'one', value: 'x' },
  { key: 'wee', value: 'y' } ]
*/
```

Note that elements which aren't in the order which is supplied are sorted at the end (under key `undefined`).

Elements with the same key are sorted at the same position.

## Rationale

This module allows a sorted order in one file to be applied to any other.

## License

MIT
