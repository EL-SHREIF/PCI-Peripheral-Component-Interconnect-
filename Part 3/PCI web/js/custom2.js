
//add animation/initialize woo
$(document).ready(function(){
	'use strict'
  new WOW().init();
});


function change1()
{
document.getElementById("put").innerHTML="register tell you about state of device(masterRead-masterWrite-slaveRead-slaverWrite-notanything";
}

function change2()
{
	document.getElementById("put").innerHTML="register tell you about if master take bus or not";
}
function change3()
{
	document.getElementById("put").innerHTML="register tell you about if target is selected or not ";
}
function change4()
{
document.getElementById("put").innerHTML="register tell you about if target can write on bus or not";
}
function change5()
{
document.getElementById("put").innerHTML="register tell you about if transaction is ended or not";
}