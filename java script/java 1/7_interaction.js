// alert("this is a message");
// It doesn't return anything
let name=prompt("what is your name?","Guest");
console.log("Player name:"+ name);
let cnfm=confirm("do you really want to delete");
if(cnfm){
    console.log("successfully deleted this");
}
else{
    alert("post not deleted yet");
}