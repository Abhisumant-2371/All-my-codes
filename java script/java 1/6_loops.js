for(i=0;i<4;i++)
{
    console.log(i);
}
while(i){
    console.log(i);
    i--;
}
let arr=["harry",3,4,5,"subham","abhisumant"];
arr.forEach(function f(element){
    console.log(element);
    
});
for(element of arr){
    console.log(element);
}
let myobj={
    name:"abhisumant",
    rollno:71
}
for(ele in myobj)
{
    console.log(`the ${ele} of employee is ${myobj[ele]}`);
}

// 4 types of loops in javascript
// -->for loop just as c++ (can be applied on string array object )
// -->for in loop can be used for those who have key vlaue pair as obj,arr,str etc;
// -->arr.forEach(function(value){console.log(value);});
//    ---->for each loop is used for array for only accessing the value (can be applied for set map other) 
// -->forof loop is use for the obj which are iterable but simple obj is not.E.g arr,str,sets
//    ---->for(let a of set.values()){cout<<a;(sorry);}; map similarly