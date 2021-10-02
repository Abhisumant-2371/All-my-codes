let flag=0;
document.getElementById('heading').addEventListener('click',function(e){
    // now e will have all the data about the click 
    let val=e.target;
    if(flag==0)
    {
        flag=flag^1;
        val.style.color="lightblue";
    }
    else{
        val.style.color="black";
        flag^=1;
    }
    
}); 