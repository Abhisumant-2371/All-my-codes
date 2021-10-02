let nav =document.getElementById('p');
// now the manipulation of the p can be done 
console.log(nav);
// nav='<p id="p">my name is abhisumant</p>';
console.log(nav);
// nav.innerHTML="<li>home</li>"
let forclass=document.getElementsByClassName('container');
// if there exist more than one container of same name then it will return it like an array and for accessing the particular one we need to access them by indexing
let sel=document.querySelector('.container')//first selector in the line will be automatically selected
let all=document.querySelectorAll('.container');
//list of nodes will be returned
