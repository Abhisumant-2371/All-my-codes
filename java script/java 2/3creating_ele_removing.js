// Creating removing and replacing the element in javascript


// Creating an html element
let newlistelement=document.createElement('li');

// giving  class to the html element
newlistelement.className="childul";

// // Adding class to html element 
newlistelement.classList.add("new-class");


// //Toggling the class 
newlistelement.classList.toggle("new-class");
// it will now remove the class and return false 

// if we use the toggle againg bring back the class and return true 
newlistelement.classList.toggle("new-class");

// removing the class permanently
newlistelement.classList.remove("new-class");

//adding id to the element 
newlistelement.id="original-id";

// selecting the first element of particular class 
let ul=document.querySelector(".this");

// adding an html element to a particular element
ul.appendChild(newlistelement);


newlistelement.innerText="to become web devloper";

// removing the element from the flow using id or whatever that focuses on the element 
// document.getElementById('only mine').parentNode.removeChild(document.getElementById('only mine'));

// replacing the child with other html element 
// ul.replaceChild(para,document.getElementById('lui'));


// setting the attribute 
ul.setAttribute('title','mytitle');

//getting the attribute
console.log(ul.hasAttribute('title'));

//removing the attribute
console.log(ul.removeAttribute('id'));
// console.log(ul.getAttribute('class'));
console.log(ul);