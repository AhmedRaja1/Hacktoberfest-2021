const readPermission = 4;
const writePermission = 2;
const executePermission = 1;

let myPermission = readPermission | writePermission;

myPermission = writePermission & executePermission;

console.log(myPermission);