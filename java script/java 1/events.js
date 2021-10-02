// Browsers events
//1.click
//2.contextmenu
//3.mouseover/mouseout
//4.mousedown/mouseup
//5.mousemove
//6.submit
//7.focus
//8.DOMContentLoaded
//9.transitionend
let para = document.getElementById('para');
para.addEventListener('mouseover', function run() {
    console.log("mouse over the para");
});
function togglehide() 
{
    let btn = document.getElementById('btn');
    let para = document.getElementById('para');
    if (para.style.display != 'none') {
        para.style.display = 'none';


    }
    else {
        para.style.display = 'block';
    }

}

