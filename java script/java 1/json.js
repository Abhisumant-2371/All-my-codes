let jsonobj={
    name:"abhisumant",
    friend:"harry",
    food:"bhindi"
}
console.log(jsonobj);
let myjsonStr=JSON.stringify(jsonobj);
console.log(myjsonStr);
// console.log(myjsonStr[1]);
console.log(myjsonStr.replace("bhindi","bangon"));
newjsonobj=JSON.parse(myjsonStr);
console.log(newjsonobj);