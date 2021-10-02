let a=34;
let name="abhisumant tiwari";
console.log(a);
console.log(name);

// operators in java script
// 1.unary operator -> -
// 2.binary operator- * + - / ** (power or exponentiation)

// Strings in java script 
let  str="This is a script";
let b=str.length;
let newstr=`this computer belongs to ${name}`;
// console.log(newstr);
// console.log("length of newstr is "+ newstr.length);
// console.log("hello i m learning\nJava script");

// String methods and function
var position=str.indexOf('is'); // gives the first occurence of the substring
// console.log(position);
var last =str.lastIndexOf('is');
// console.log(last);
var substr1=str.substring(1,4);
console.log(substr1);
// str.slice(1,2) can also take negative value

// str.substr(start indexe, length of the string required);
let ads=newstr.substr(0,4);
// console.log(ads);
//str.replace(str1,str2);
var strwithwhitespaces="    ajd    ajdj ... a kdjasdk ";
// console.log(strwithwhitespaces);
console.log(strwithwhitespaces.trim());
let ch=str.charAt(2);
let bb=str.charCodeAt(2);
// console.log(bb-32);