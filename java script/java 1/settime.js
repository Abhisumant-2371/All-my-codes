// setTimeout-->Allows us to run the function once after the interval of time 
// clearTimeout-->Allows us to run the function repeatedly after the interval of time

function greet(name) {
    console.log("hello " + name);

}
// timeOut=setTimeout(greet,5000,"harry");//just name of function is required.
// console.log(timeOut);
// clearTimeout(timeOut);
// intervalId=setInterval(greet,1000);
// clearInterval(intervalId);
function displayTime() {
    time=new Date();
    console.log(time);
    document.getElementById('time').innerHTML=time;
}
setInterval(displayTime,1000);
