var buttonid=document.querySelectorAll("button");

var turnp1;
var turnp2;
var signp1;
var signp2;
var turndisplay=document.getElementById("turn");
var l1=document.getElementById("1");
var l2=document.getElementById("10");
var l3=document.getElementById("19");
var l4=document.getElementById("11");
var l5=document.getElementById("20");
var l6=document.getElementById("29");
var l7=document.getElementById("21");
var l8=document.getElementById("30");
var l9=document.getElementById("39");
var turndisplay=document.getElementById("turn");
var chance1=0;
var chance2=0;
var sort=new Array();

var player1=new Array();
var player2=new Array();
var temp;
var disableother;
var starting;
var starting2;
var starting3;
var sort2=new Array();

$(document).ready(function(){



	$('#turn').fadeOut("fast");

	$('#player1c1').click('change',function(){
		this.disabled=true;
		
		$("#player2c2").attr("disabled",true);
		
		signp1="X";
		
		signp2="O";

		
		$('#p1c2').fadeOut("slow");
		$('#p2c1').fadeOut('slow');
		$('#turn').show("fast");
		turndisplay.textContent="X TURN";


if(signp1=="X")
{
	turnp1=0;
	turnp2=1;
}
else if(signp2=="X")
{
  turnp2=0;
  turnp1=1;
}
	
	document.getElementById("1").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("10").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("19").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("11").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("20").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("29").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("21").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("30").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("39").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}



l1.addEventListener("click",function(){

	
	var block=l1.getAttribute("Id");
	if(turnp1==0)
	{   l1.textContent="X";
l1.style.transition="0.6s";
        l1.style.fontSize=" 90px";
        l1.style.fontStyle="Bold";
  		l1.style.objectFit="cover";
  		l1.style.color="white";
        l1.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="O TURN";

		if(chance1>=3)
		{
			 status1();
		}
	}
	else if(turnp2==0)
	{    l1.textContent="O";
        l1.style.transition="0.5s";
        l1.style.fontSize=" 90px";
        l1.style.fontStyle="Bold";
  		l1.style.objectFit="cover";
  		l1.style.color="white";
  		
  	
        l1.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="X TURN";
	}
	
	




});
l2.addEventListener("click",function(){
	
	var block=l2.getAttribute("Id");
	if(turnp1==0)
	{
		l2.textContent="X";
		l2.style.transition="0.6s";
        l2.style.fontSize=" 90px";
        l2.style.fontStyle="Bold";
  		l2.style.objectFit="cover";
  		l2.style.color="white";
        l2.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="O TURN";
		if(chance1>=3)
		{
			status1();

		}
	}
	else if(turnp2==0)
	{   l2.textContent="O";
        l2.style.transition="0.5s";
        l2.style.fontSize=" 90px";
        l2.style.fontStyle="Bold";
  		l2.style.objectFit="cover";
  		l2.style.color="white";
  		
  	
        l2.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="X TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});
l3.addEventListener("click",function(){
	
	var block=l3.getAttribute("Id");
	if(turnp1==0)
	{
		l3.textContent="X";
		l3.style.transition="0.6s";
        l3.style.fontSize=" 90px";
        l3.style.fontStyle="Bold";
  		l3.style.objectFit="cover";
  		l3.style.color="white";
        l3.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="O TURN";
		if(chance1>=3)
		{
			status1();

		}
	}
	else if(turnp2==0
)
	{   l3.textContent="O";
        l3.style.transition="0.5s";
        l3.style.fontSize=" 90px";
        l3.style.fontStyle="Bold";
  		l3.style.objectFit="cover";
  		l3.style.color="white";
  		
  	
        l3.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="X TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	




});

l4.addEventListener("click",function(){
	
	var block=l4.getAttribute("Id");
	if(turnp1==0
)
	{
		l4.textContent="X";
		l4.style.transition="0.6s";
        l4.style.fontSize=" 90px";
        l4.style.fontStyle="Bold";
  		l4.style.objectFit="cover";
  		l4.style.color="white";
        l4.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="O TURN";

		if(chance1>=3)
		{
			status1();

		}
	}
	else if(turnp2==0
)
	{    l4.textContent="O";
        l4.style.transition="0.5s";
        l4.style.fontSize=" 90px";
        l4.style.fontStyle="Bold";
  		l4.style.objectFit="cover";
  		l4.style.color="white";
  		
  	
        l4.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="X TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});
l5.addEventListener("click",function(){
	
	var block=l5.getAttribute("Id");
	if(turnp1==0
)
	{
		l5.textContent="X";
		l5.style.transition="0.6s";
        l5.style.fontSize=" 90px";
        l5.style.fontStyle="Bold";
  		l5.style.objectFit="cover";
  		l5.style.color="white";
        l5.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;

		turndisplay.textContent="O TURN";
		if(chance1>=3)
		{
			status1();

		}
	}
	else if(turnp2==0
)
	{    l5.textContent="O";
        l5.style.transition="0.5s";
        l5.style.fontSize=" 90px";
        l5.style.fontStyle="Bold";
  		l5.style.objectFit="cover";
  		
  	
        l5.style.transitionTimingFunction="ease-in";
        l5.style.color="white";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="X TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});

l6.addEventListener("click",function(){
	
	var block=l6.getAttribute("Id");
	if(turnp1==0
)
	{
		l6.textContent="X";
		l6.style.transition="0.6s";
        l6.style.fontSize=" 90px";
        l6.style.fontStyle="Bold";
  		l6.style.objectFit="cover";
  		l6.style.color="white";
        l6.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="O TURN";
		if(chance1>=3)
		{
			status1();

		}
		
	}
	else if(turnp2==0
)
	{   l6.textContent="O";
        l6.style.transition="0.5s";
        l6.style.fontSize=" 90px";
        l6.style.fontStyle="Bold";
  		l6.style.objectFit="cover";
  		l6.style.color="white";
  		
  	
        l6.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="X TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});
l7.addEventListener("click",function(){
	
	var block=l7.getAttribute("Id");
	if(turnp1==0
)
	{
		l7.textContent="X";
		l7.style.transition="0.6s";
        l7.style.fontSize=" 90px";
        l7.style.fontStyle="Bold";
  		l7.style.objectFit="cover";
  		l7.style.color="white";
        l7.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="O TURN";
		if(chance1>=3)
		{
			status1();

		}
		
		
	}
	else if(turnp2==0)
	{    l7.textContent="O";

        l7.style.transition="0.5s";
        l7.style.fontSize=" 90px";
        l7.style.fontStyle="Bold";
  		l7.style.objectFit="cover";
  		l7.style.color="white";
  		
  	
        l7.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="X TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});
l8.addEventListener("click",function(){
	
	var block=l8.getAttribute("Id");
	if(turnp1==0
)
	{
		l8.textContent="X";
		l8.style.transition="0.6s";
        l8.style.fontSize=" 90px";
        l8.style.fontStyle="Bold";
  		l8.style.objectFit="cover";
  		l8.style.color="white";
        l8.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="O TURN";
		if(chance1>=3)
		{
			status1();

		}
		
	}
	else if(turnp2==0
)
	{   l8.textContent="O";
        l8.style.transition="0.5s";
        l8.style.fontSize=" 90px";
        l8.style.fontStyle="Bold";
  		l8.style.objectFit="cover";
  		l8.style.color="white";
  		
  	
        l8.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="X TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});
l9.addEventListener("click",function(){
	
	var block=l9.getAttribute("Id");
	if(turnp1==0)
	{
		l9.textContent="X";
		l9.style.transition="0.6s";
        l9.style.fontSize=" 90px";
        l9.style.fontStyle="Bold";
  		l9.style.objectFit="cover";
  		l9.style.color="white";
        l9.style.transitionTimingFunction="ease-in";
       
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="O TURN";
		if(chance1>=3)
		{
			status1();

		}
		
	}
	else if(turnp2==0)
	{   l9.textContent="O";
        l9.style.transition="0.5s";
        l9.style.fontSize=" 90px";
        l9.style.fontStyle="Bold";
  		l9.style.objectFit="cover";
  		l9.style.color="white";
  	
        l9.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="X TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




  });
function status1(){
   for(var m=0;m<chance1;m++)
  {
  		sort[m]=player1[m];
  }
  	
  	 
	
	for(var k=0;k<chance1;k++)
	{
       for(var m=k+1;m<chance1;m++)
       {
       	if(sort[k]>sort[m])
       	{
       		temp=sort[k];
       		sort[k]=sort[m];
       		sort[m]=temp;

       	}
       }
	}
	for(var n=0;n<chance1-2;n++)
    {	
  	  if((sort[n+1]-sort[n])==(sort[n+2]-sort[n+1]))
  	  {      
             starting=sort[n];
             starting2=sort[n+1]
             starting3=sort[n+2];
             setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);
             
             $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 1 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
             
              
             // $("#showcase").fadeOut(1000,function(){
              	//$('#showcase').replaceWith("<h2>PLAYER 1 WON</h2>");
              	//$("h2").css("margin-left","40%");
              	//$("h2").css("transform","scale(1.01)");
              	//$("#showcase").fadeIn("slow");
             

              //});
              

             
            
             
  	  }
}
         for(var p=0;p<chance1;p++)
    {
    	for(var q=p+1;q<chance1;q++)
    	{
    		if(2*(sort[q]-sort[p])==sort[q+2]-sort[p])
    		{
    			 starting=sort[p];
                            starting2=sort[p+1];
                            starting3=sort[p+3];
                             setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);
    			$('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 1 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
    			}
    		}
    	}
    	for(var r=0;r<chance1;r++)
     {
     	for(var e=r+2;e<chance1;e++)
     	{
     		if(2*(sort[e]-sort[r])==sort[e+1]-sort[r])
     		{     starting=sort[r];
                            starting2=sort[r+2];
                            starting3=sort[r+3];
                            setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);
                    $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 1 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
     		}
     	}
     }
     if(chance1==5)
{
  	 $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "AAAHH!",
  text: "MATCH DRAWN",
  icon: "warning",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
}


   }
   function player2()
   {
   	for(i=0;i<chance2;i++)
   	{
   		sort2[i]=player2[i];

   	}
   	for(var k=0;k<chance2;k++)
	{
       for(var m=k+1;m<chance2;m++)
       {
       	if(sort2[k]>sort2[m])
       	{
       		temp=sort2[k];
       		sort2[k]=sort2[m];
       		sort2[m]=temp;

       	}
       }
	}
	for(var n=0;n<chance2-2;n++)
    {	
  	  if((sort2[n+1]-sort2[n])==(sort2[n+2]-sort2[n+1]))
  	  {      
             starting=sort2[n];
             starting2=sort2[n+1]
             starting3=sort2[n+2];
             setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);
             
             $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 2 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
             
              
             // $("#showcase").fadeOut(1000,function(){
              	//$('#showcase').replaceWith("<h2>PLAYER 1 WON</h2>");
              	//$("h2").css("margin-left","40%");
              	//$("h2").css("transform","scale(1.01)");
              	//$("#showcase").fadeIn("slow");
             

              //});
              

             
            
             
  	  }
}
         for(var p=0;p<chance2;p++)
    {
    	for(var q=p+1;q<chance2;q++)
    	{
    		if(2*(sort2[q]-sort2[p])==sort2[q+2]-sort2[p])
    		{   starting=sort2[p];
                            starting2=sort2[p+1];
                            starting3=sort2[p+3];
                             setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);
    			$('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 2 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
    			return;
    			}
    		}
    	}
    	for(var r=0;r<chance2;r++)
     {
     	for(var e=r+2;e<chance2;e++)
     	{
     		if(2*(sort2[e]-sort2[r])==sort2[e+1]-sort2[r])
     		{     starting=sort2[r];
                            starting2=sort2[r+2];
                            starting3=sort2[r+3];
                            setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);
                  $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 2 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
     		}
     	}
     }

   }

   



if(chance2==5)
{
  	 $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "AAAHH!",
  text: "MATCH DRAWN",
  icon: "warning",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
}
		
     

		


	});
	$('#player1c2').click(function(){
		this.disabled=true;
         signp1="O";
         signp2="X";
         $("#player2c1").attr("disabled",true);
		
		$('#p1c1').fadeOut("slow");
		$('#p2c2').fadeOut("slow");
		$('#turn').show("fast");
		turnp1=1;
		turnp2=0;
		turndisplay.textContent="X TURN";
		document.getElementById("1").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("10").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("19").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("11").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("20").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("29").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("21").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("30").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("39").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
l1.addEventListener("click",function(){

	
	var block=l1.getAttribute("Id");
	if(turnp1==0)
	{   l1.textContent="O";
l9.style.transition="0.6s";
        l1.style.fontSize=" 90px";
        l1.style.fontStyle="Bold";
  		l1.style.objectFit="cover";
  		l1.style.color="white";
        l1.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="X TURN";

		if(chance1>=3)
		{
			 status1();
		}
	}
	else if(turnp2==0)
	{    l1.textContent="X";
        l1.style.transition="0.5s";
        l1.style.fontSize=" 90px";
        l1.style.fontStyle="Bold";
  		l1.style.objectFit="cover";
  		l1.style.color="white";
  		
  	
        l1.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="O TURN";
	}
	
	




});
l2.addEventListener("click",function(){
	
	var block=l2.getAttribute("Id");
	if(turnp1==0)
	{
		l2.textContent="O";
		l2.style.transition="0.6s";
        l2.style.fontSize=" 90px";
        l2.style.fontStyle="Bold";
  		l2.style.objectFit="cover";
  		l2.style.color="white";
        l2.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="X TURN";
		if(chance1>=3)
		{
			status1();

		}
	}
	else if(turnp2==0)
	{   l2.textContent="X";
        l2.style.transition="0.5s";
        l2.style.fontSize=" 90px";
        l2.style.fontStyle="Bold";
  		l2.style.objectFit="cover";
  		l2.style.color="white";
  		
  	
        l2.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="O TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});
l3.addEventListener("click",function(){
	
	var block=l3.getAttribute("Id");
	if(turnp1==0)
	{
		l3.textContent="O";
		l3.style.transition="0.6s";
        l3.style.fontSize=" 90px";
        l3.style.fontStyle="Bold";
  		l3.style.objectFit="cover";
  		l3.style.color="white";
        l3.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="X TURN";
		if(chance1>=3)
		{
			status1();

		}
	}
	else if(turnp2==0
)
	{   l3.textContent="X";
        l3.style.transition="0.5s";
        l3.style.fontSize=" 90px";
        l3.style.fontStyle="Bold";
  		l3.style.objectFit="cover";
  		l3.style.color="white";
  		
  	
        l3.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="O TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	




});

l4.addEventListener("click",function(){
	
	var block=l4.getAttribute("Id");
	if(turnp1==0
)
	{
		l4.textContent="O";
		l4.style.transition="0.6s";
        l4.style.fontSize=" 90px";
        l4.style.fontStyle="Bold";
  		l4.style.objectFit="cover";
  		l4.style.color="white";
        l4.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="X TURN";

		if(chance1>=3)
		{
			status1();

		}
	}
	else if(turnp2==0
)
	{    l4.textContent="X";
        l4.style.transition="0.5s";
        l4.style.fontSize=" 90px";
        l4.style.fontStyle="Bold";
  		l4.style.objectFit="cover";
  		l4.style.color="white";
  		
  	
        l4.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="O TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});
l5.addEventListener("click",function(){
	
	var block=l5.getAttribute("Id");
	if(turnp1==0
)
	{
		l5.textContent="O";
		l5.style.transition="0.6s";
        l5.style.fontSize=" 90px";
        l5.style.fontStyle="Bold";
  		l5.style.objectFit="cover";
  		l5.style.color="white";
        l5.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;

		turndisplay.textContent="X TURN";
		if(chance1>=3)
		{
			status1();

		}
	}
	else if(turnp2==0
)
	{    l5.textContent="X";
        l5.style.transition="0.5s";
        l5.style.fontSize=" 90px";
        l5.style.fontStyle="Bold";
  		l5.style.objectFit="cover";
  		
  	
        l5.style.transitionTimingFunction="ease-in";
        l5.style.color="white";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="O TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});

l6.addEventListener("click",function(){
	
	var block=l6.getAttribute("Id");
	if(turnp1==0
)
	{
		l6.textContent="O";
		l6.style.transition="0.6s";
        l6.style.fontSize=" 90px";
        l6.style.fontStyle="Bold";
  		l6.style.objectFit="cover";
  		l6.style.color="white";
        l6.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="X TURN";
		if(chance1>=3)
		{
			status1();

		}
		
	}
	else if(turnp2==0
)
	{   l6.textContent="X";
        l6.style.transition="0.5s";
        l6.style.fontSize=" 90px";
        l6.style.fontStyle="Bold";
  		l6.style.objectFit="cover";
  		l6.style.color="white";
  		
  	
        l6.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="O TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});
l7.addEventListener("click",function(){
	
	var block=l7.getAttribute("Id");
	if(turnp1==0
)
	{
		l7.textContent="O";
		l7.style.transition="0.6s";
        l7.style.fontSize=" 90px";
        l7.style.fontStyle="Bold";
  		l7.style.objectFit="cover";
  		l7.style.color="white";
        l7.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="X TURN";
		if(chance1>=3)
		{
			status1();

		}
		
		
	}
	else if(turnp2==0)
	{    l7.textContent="X";

        l7.style.transition="0.5s";
        l7.style.fontSize=" 90px";
        l7.style.fontStyle="Bold";
  		l7.style.objectFit="cover";
  		l7.style.color="white";
  		
  	
        l7.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="O TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});
l8.addEventListener("click",function(){
	
	var block=l8.getAttribute("Id");
	if(turnp1==0
)
	{
		l8.textContent="O";
		l8.style.transition="0.6s";
        l8.style.fontSize=" 90px";
        l8.style.fontStyle="Bold";
  		l8.style.objectFit="cover";
  		l8.style.color="white";
        l8.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="X TURN";
		if(chance1>=3)
		{
			status1();

		}
		
	}
	else if(turnp2==0
)
	{   l8.textContent="X";
        l8.style.transition="0.5s";
        l8.style.fontSize=" 90px";
        l8.style.fontStyle="Bold";
  		l8.style.objectFit="cover";
  		l8.style.color="white";
  		
  	
        l8.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="O TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});
l9.addEventListener("click",function(){
	
	var block=l9.getAttribute("Id");
	if(turnp1==0)
	{
		l9.textContent="O";
		l9.style.transition="0.6s";
        l9.style.fontSize=" 90px";
        l9.style.fontStyle="Bold";
  		l9.style.objectFit="cover";
  		l9.style.color="white";
        l9.style.transitionTimingFunction="ease-in";
       
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="X TURN";
		if(chance1>=3)
		{
			status1();

		}
		
	}
	else if(turnp2==0)
	{   l9.textContent="X";
        l9.style.transition="0.5s";
        l9.style.fontSize=" 90px";
        l9.style.fontStyle="Bold";
  		l9.style.objectFit="cover";
  		l9.style.color="white";
  	
        l9.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="O TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




  });
function status1(){
   for(var m=0;m<chance1;m++)
  {
  		sort[m]=player1[m];
  }
  	
  	 
	
	for(var k=0;k<chance1;k++)
	{
       for(var m=k+1;m<chance1;m++)
       {
       	if(sort[k]>sort[m])
       	{
       		temp=sort[k];
       		sort[k]=sort[m];
       		sort[m]=temp;

       	}
       }
	}
	for(var n=0;n<chance1-2;n++)
    {	
  	  if((sort[n+1]-sort[n])==(sort[n+2]-sort[n+1]))
  	  {      
             starting=sort[n];
             starting2=sort[n+1]
             starting3=sort[n+2];
             setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);
             
             $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 1 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
             
              
             // $("#showcase").fadeOut(1000,function(){
              	//$('#showcase').replaceWith("<h2>PLAYER 1 WON</h2>");
              	//$("h2").css("margin-left","40%");
              	//$("h2").css("transform","scale(1.01)");
              	//$("#showcase").fadeIn("slow");
             

              //});
              

             
            
             
  	  }
}
         for(var p=0;p<chance1;p++)
    {
    	for(var q=p+1;q<chance1;q++)
    	{
    		if(2*(sort[q]-sort[p])==sort[q+2]-sort[p])
    		{
    			 starting=sort[p];
                            starting2=sort[p+1];
                            starting3=sort[p+3];
                             setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);
    			$('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 1 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
    			}
    		}
    	}
    	for(var r=0;r<chance1;r++)
     {
     	for(var e=r+2;e<chance1;e++)
     	{
     		if(2*(sort[e]-sort[r])==sort[e+1]-sort[r])
     		{ 
               starting=sort[r];
                            starting2=sort[r+2];
                            starting3=sort[r+3];

     		 setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);
                   $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 1 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
     		}
     	}
     }
     if(chance1==5)
{
  	 $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "AAAHH!",
  text: "MATCH DRAWN",
  icon: "warning",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
}


   }
   function player2()
   {
   	for(i=0;i<chance2;i++)
   	{
   		sort2[i]=player2[i];

   	}
   	for(var k=0;k<chance2;k++)
	{
       for(var m=k+1;m<chance2;m++)
       {
       	if(sort2[k]>sort2[m])
       	{
       		temp=sort2[k];
       		sort2[k]=sort2[m];
       		sort2[m]=temp;

       	}
       }
	}
	for(var n=0;n<chance2-2;n++)
    {	
  	  if((sort2[n+1]-sort2[n])==(sort2[n+2]-sort2[n+1]))
  	  {      
             starting=sort2[n];
             starting2=sort2[n+1]
             starting3=sort2[n+2];
             setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);
             
             $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 2 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
             
              
             // $("#showcase").fadeOut(1000,function(){
              	//$('#showcase').replaceWith("<h2>PLAYER 1 WON</h2>");
              	//$("h2").css("margin-left","40%");
              	//$("h2").css("transform","scale(1.01)");
              	//$("#showcase").fadeIn("slow");
             

              //});
              

             
            
             
  	  }
}
         for(var p=0;p<chance2;p++)
    {
    	for(var q=p+1;q<chance2;q++)
    	{
    		if(2*(sort2[q]-sort2[p])==sort2[q+2]-sort2[p])
    		{   starting=sort2[p];
                            starting2=sort2[p+1];
                            starting3=sort2[p+3];
                             setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);

    			$('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 2 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
    			return;
    			}
    		}
    	}
    	for(var r=0;r<chance2;r++)
     {
     	for(var e=r+2;e<chance2;e++)
     	{
     		if(2*(sort2[e]-sort2[r])==sort2[e+1]-sort2[r])
     		{     starting=sort2[r];
                            starting2=sort2[r+2];
                            starting3=sort2[r+3];
                            setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);
                  $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 2 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
     		}
     	}
     }

   

if(chance2==5)
{
  	 $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "AAAHH!",
  text: "MATCH DRAWN",
  icon: "warning",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
}
		

	}	


	




		


	});

	$('#player2c1').click(function(){
		 signp2="X";
		 signp1="O";
		 this.disabled=true;
		 $('#player1c2').attr("disabled",true);

		
		$('#p2c2').fadeOut("slow");
		$('#p1c1').fadeOut("slow");
		$('#turn').show("fast");
		turndisplay.textContent="X TURN";
		turnp2=0;
		turnp1=1;
		
       
		document.getElementById("1").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("10").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("19").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("11").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("20").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("29").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("21").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("30").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("39").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
l1.addEventListener("click",function(){

	
	var block=l1.getAttribute("Id");
	if(turnp1==0)
	{   l1.textContent="O";
l1.style.transition="0.6s";
        l1.style.fontSize=" 90px";
        l1.style.fontStyle="Bold";
  		l1.style.objectFit="cover";
  		l1.style.color="white";
        l1.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="X TURN";

		if(chance1>=3)
		{
			 status1();
		}
	}
	else if(turnp2==0)
	{    l1.textContent="X";
        l1.style.transition="0.5s";
        l1.style.fontSize=" 90px";
        l1.style.fontStyle="Bold";
  		l1.style.objectFit="cover";
  		l1.style.color="white";
  		
  	
        l1.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="O TURN";
	}
	
	




});
l2.addEventListener("click",function(){
	
	var block=l2.getAttribute("Id");
	if(turnp1==0)
	{
		l2.textContent="O";
		l2.style.transition="0.6s";
        l2.style.fontSize=" 90px";
        l2.style.fontStyle="Bold";
  		l2.style.objectFit="cover";
  		l2.style.color="white";
        l2.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="X TURN";
		if(chance1>=3)
		{
			status1();

		}
	}
	else if(turnp2==0)
	{   l2.textContent="X";
        l2.style.transition="0.5s";
        l2.style.fontSize=" 90px";
        l2.style.fontStyle="Bold";
  		l2.style.objectFit="cover";
  		l2.style.color="white";
  		
  	
        l2.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="O TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});
l3.addEventListener("click",function(){
	
	var block=l3.getAttribute("Id");
	if(turnp1==0)
	{
		l3.textContent="O";
		l3.style.transition="0.6s";
        l3.style.fontSize=" 90px";
        l3.style.fontStyle="Bold";
  		l3.style.objectFit="cover";
  		l3.style.color="white";
        l3.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="X TURN";
		if(chance1>=3)
		{
			status1();

		}
	}
	else if(turnp2==0
)
	{   l3.textContent="X";
        l3.style.transition="0.5s";
        l3.style.fontSize=" 90px";
        l3.style.fontStyle="Bold";
  		l3.style.objectFit="cover";
  		l3.style.color="white";
  		
  	
        l3.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="O TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	




});

l4.addEventListener("click",function(){
	
	var block=l4.getAttribute("Id");
	if(turnp1==0
)
	{
		l4.textContent="O";
		l4.style.transition="0.6s";
        l4.style.fontSize=" 90px";
        l4.style.fontStyle="Bold";
  		l4.style.objectFit="cover";
  		l4.style.color="white";
        l4.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="X TURN";

		if(chance1>=3)
		{
			status1();

		}
	}
	else if(turnp2==0
)
	{    l4.textContent="X";
        l4.style.transition="0.5s";
        l4.style.fontSize=" 90px";
        l4.style.fontStyle="Bold";
  		l4.style.objectFit="cover";
  		l4.style.color="white";
  		
  	
        l4.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="O TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});
l5.addEventListener("click",function(){
	
	var block=l5.getAttribute("Id");
	if(turnp1==0
)
	{
		l5.textContent="O";
		l5.style.transition="0.6s";
        l5.style.fontSize=" 90px";
        l5.style.fontStyle="Bold";
  		l5.style.objectFit="cover";
  		l5.style.color="white";
        l5.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;

		turndisplay.textContent="X TURN";
		if(chance1>=3)
		{
			status1();

		}
	}
	else if(turnp2==0
)
	{    l5.textContent="X";
        l5.style.transition="0.5s";
        l5.style.fontSize=" 90px";
        l5.style.fontStyle="Bold";
  		l5.style.objectFit="cover";
  		
  	
        l5.style.transitionTimingFunction="ease-in";
        l5.style.color="white";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="O TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});

l6.addEventListener("click",function(){
	
	var block=l6.getAttribute("Id");
	if(turnp1==0
)
	{
		l6.textContent="O";
		l6.style.transition="0.6s";
        l6.style.fontSize=" 90px";
        l6.style.fontStyle="Bold";
  		l6.style.objectFit="cover";
  		l6.style.color="white";
        l6.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="X TURN";
		if(chance1>=3)
		{
			status1();

		}
		
	}
	else if(turnp2==0
)
	{   l6.textContent="X";
        l6.style.transition="0.5s";
        l6.style.fontSize=" 90px";
        l6.style.fontStyle="Bold";
  		l6.style.objectFit="cover";
  		l6.style.color="white";
  		
  	
        l6.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="O TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});
l7.addEventListener("click",function(){
	
	var block=l7.getAttribute("Id");
	if(turnp1==0
)
	{
		l7.textContent="O";
		l7.style.transition="0.6s";
        l7.style.fontSize=" 90px";
        l7.style.fontStyle="Bold";
  		l7.style.objectFit="cover";
  		l7.style.color="white";
        l7.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="X TURN";
		if(chance1>=3)
		{
			status1();

		}
		
		
	}
	else if(turnp2==0)
	{    l7.textContent="X";

        l7.style.transition="0.5s";
        l7.style.fontSize=" 90px";
        l7.style.fontStyle="Bold";
  		l7.style.objectFit="cover";
  		l7.style.color="white";
  		
  	
        l7.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="O TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});
l8.addEventListener("click",function(){
	
	var block=l8.getAttribute("Id");
	if(turnp1==0
)
	{
		l8.textContent="O";
		l8.style.transition="0.6s";
        l8.style.fontSize=" 90px";
        l8.style.fontStyle="Bold";
  		l8.style.objectFit="cover";
  		l8.style.color="white";
        l8.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="X TURN";
		if(chance1>=3)
		{
			status1();

		}
		
	}
	else if(turnp2==0
)
	{   l8.textContent="X";
        l8.style.transition="0.5s";
        l8.style.fontSize=" 90px";
        l8.style.fontStyle="Bold";
  		l8.style.objectFit="cover";
  		l8.style.color="white";
  		
  	
        l8.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="O TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});
l9.addEventListener("click",function(){
	
	var block=l9.getAttribute("Id");
	if(turnp1==0)
	{
		l9.textContent="O";
		l9.style.transition="0.6s";
        l9.style.fontSize=" 90px";
        l9.style.fontStyle="Bold";
  		l9.style.objectFit="cover";
  		l9.style.color="white";
        l9.style.transitionTimingFunction="ease-in";
       
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="X TURN";
		if(chance1>=3)
		{
			status1();

		}
		
	}
	else if(turnp2==0)
	{   l9.textContent="X";
        l9.style.transition="0.5s";
        l9.style.fontSize=" 90px";
        l9.style.fontStyle="Bold";
  		l9.style.objectFit="cover";
  		l9.style.color="white";
  	
        l9.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="O TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




  });
function status1(){
   for(var m=0;m<chance1;m++)
  {
  		sort[m]=player1[m];
  }
  	
  	 
	
	for(var k=0;k<chance1;k++)
	{
       for(var m=k+1;m<chance1;m++)
       {
       	if(sort[k]>sort[m])
       	{
       		temp=sort[k];
       		sort[k]=sort[m];
       		sort[m]=temp;

       	}
       }
	}
	for(var n=0;n<chance1-2;n++)
    {	
  	  if((sort[n+1]-sort[n])==(sort[n+2]-sort[n+1]))
  	  {      
             starting=sort[n];
             starting2=sort[n+1]
             starting3=sort[n+2];
             setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);
             
             $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 1 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
             
              
             // $("#showcase").fadeOut(1000,function(){
              	//$('#showcase').replaceWith("<h2>PLAYER 1 WON</h2>");
              	//$("h2").css("margin-left","40%");
              	//$("h2").css("transform","scale(1.01)");
              	//$("#showcase").fadeIn("slow");
             

              //});
              

             
            
             
  	  }
}
         for(var p=0;p<chance1;p++)
    {
    	for(var q=p+1;q<chance1;q++)
    	{
    		if(2*(sort[q]-sort[p])==sort[q+2]-sort[p])
    		{   starting=sort[p];
                            starting2=sort[p+1];
                            starting3=sort[p+3];
                             setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);
    			$('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 1 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
    			}
    		}
    	}
    	for(var r=0;r<chance1;r++)
     {
     	for(var e=r+2;e<chance1;e++)
     	{
     		if(2*(sort[e]-sort[r])==sort[e+1]-sort[r])
     		{     starting=sort[r];
                            starting2=sort[r+2];
                            starting3=sort[r+3];

     		 setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);
                    $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 1 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
     		}
     	}
     }
     if(chance1==5)
{
  	 $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "AAAHH!",
  text: "MATCH DRAWN",
  icon: "warning",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
}


   }
   function player2()
   {
   	for(i=0;i<chance2;i++)
   	{
   		sort2[i]=player2[i];

   	}
   	for(var k=0;k<chance2;k++)
	{
       for(var m=k+1;m<chance2;m++)
       {
       	if(sort2[k]>sort2[m])
       	{
       		temp=sort2[k];
       		sort2[k]=sort2[m];
       		sort2[m]=temp;

       	}
       }
	}
	for(var n=0;n<chance2-2;n++)
    {	
  	  if((sort2[n+1]-sort2[n])==(sort2[n+2]-sort2[n+1]))
  	  {      
             starting=sort2[n];
             starting2=sort2[n+1]
             starting3=sort2[n+2];
             setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);
             
             $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 2 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
             
              
             // $("#showcase").fadeOut(1000,function(){
              	//$('#showcase').replaceWith("<h2>PLAYER 1 WON</h2>");
              	//$("h2").css("margin-left","40%");
              	//$("h2").css("transform","scale(1.01)");
              	//$("#showcase").fadeIn("slow");
             

              //});
              

             
            
             
  	  }
}
         for(var p=0;p<chance2;p++)
    {
    	for(var q=p+1;q<chance2;q++)
    	{
    		if(2*(sort2[q]-sort2[p])==sort2[q+2]-sort2[p])
    		{   starting=sort2[p];
                            starting2=sort2[p+1];
                            starting3=sort2[p+3];
                             setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);
    			$('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 2 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
    			return;
    			}
    		}
    	}
    	for(var r=0;r<chance2;r++)
     {
     	for(var e=r+2;e<chance2;e++)
     	{
     		if(2*(sort2[e]-sort2[r])==sort2[e+1]-sort2[r])
     		{     starting=sort2[r];
                            starting2=sort2[r+2];
                            starting3=sort2[r+3];
                            setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);
                  $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 2 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
     		}
     	}
     }

   }

if(chance2==5)
{
  	 $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "AAAHH!",
  text: "MATCH DRAWN",
  icon: "warning",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
}

		

		



	});
	$('#player2c2').click(function(){

         signp2="O";
         signp1="X";
		
		$('#p2c1').fadeOut("slow");
		$('#p1c2').fadeOut("slow");
		$('#turn').show("fast");
		turndisplay.textContent="X TURN";
		if(signp1=="X")
{
	turnp1=0;
	turnp2=1;
}
else if(signp2=="X")
{
  turnp2=0;
  turnp1=1;
}
	
	document.getElementById("1").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("10").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("19").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("11").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("20").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("29").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("21").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("30").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}
document.getElementById("39").onclick = function() {
    //disable
    this.disabled = true;

    //do some validation stuff
}



l1.addEventListener("click",function(){

	
	var block=l1.getAttribute("Id");
	if(turnp1==0)
	{   l1.textContent="X";
l9.style.transition="0.6s";
        l1.style.fontSize=" 90px";
        l1.style.fontStyle="Bold";
  		l1.style.objectFit="cover";
  		l1.style.color="white";
        l1.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="O TURN";

		if(chance1>=3)
		{
			 status1();
		}
	}
	else if(turnp2==0)
	{    l1.textContent="O";
        l1.style.transition="0.5s";
        l1.style.fontSize=" 90px";
        l1.style.fontStyle="Bold";
  		l1.style.objectFit="cover";
  		l1.style.color="white";
  		
  	
        l1.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="X TURN";
	}
	
	




});
l2.addEventListener("click",function(){
	
	var block=l2.getAttribute("Id");
	if(turnp1==0)
	{
		l2.textContent="X";
		l2.style.transition="0.6s";
        l2.style.fontSize=" 90px";
        l2.style.fontStyle="Bold";
  		l2.style.objectFit="cover";
  		l2.style.color="white";
        l2.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="O TURN";
		if(chance1>=3)
		{
			status1();

		}
	}
	else if(turnp2==0)
	{   l2.textContent="O";
        l2.style.transition="0.5s";
        l2.style.fontSize=" 90px";
        l2.style.fontStyle="Bold";
  		l2.style.objectFit="cover";
  		l2.style.color="white";
  		
  	
        l2.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="X TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});
l3.addEventListener("click",function(){
	
	var block=l3.getAttribute("Id");
	if(turnp1==0)
	{
		l3.textContent="X";
		l3.style.transition="0.6s";
        l3.style.fontSize=" 90px";
        l3.style.fontStyle="Bold";
  		l3.style.objectFit="cover";
  		l3.style.color="white";
        l3.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="O TURN";
		if(chance1>=3)
		{
			status1();

		}
	}
	else if(turnp2==0
)
	{   l3.textContent="O";
        l3.style.transition="0.5s";
        l3.style.fontSize=" 90px";
        l3.style.fontStyle="Bold";
  		l3.style.objectFit="cover";
  		l3.style.color="white";
  		
  	
        l3.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="X TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	




});

l4.addEventListener("click",function(){
	
	var block=l4.getAttribute("Id");
	if(turnp1==0
)
	{
		l4.textContent="X";
		l4.style.transition="0.6s";
        l4.style.fontSize=" 90px";
        l4.style.fontStyle="Bold";
  		l4.style.objectFit="cover";
  		l4.style.color="white";
        l4.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="O TURN";

		if(chance1>=3)
		{
			status1();

		}
	}
	else if(turnp2==0
)
	{    l4.textContent="O";
        l4.style.transition="0.5s";
        l4.style.fontSize=" 90px";
        l4.style.fontStyle="Bold";
  		l4.style.objectFit="cover";
  		l4.style.color="white";
  		
  	
        l4.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="X TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});
l5.addEventListener("click",function(){
	
	var block=l5.getAttribute("Id");
	if(turnp1==0
)
	{
		l5.textContent="X";
		l5.style.transition="0.6s";
        l5.style.fontSize=" 90px";
        l5.style.fontStyle="Bold";
  		l5.style.objectFit="cover";
  		l5.style.color="white";
        l5.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;

		turndisplay.textContent="O TURN";
		if(chance1>=3)
		{
			status1();

		}
	}
	else if(turnp2==0
)
	{    l5.textContent="O";
        l5.style.transition="0.5s";
        l5.style.fontSize=" 90px";
        l5.style.fontStyle="Bold";
  		l5.style.objectFit="cover";
  		
  	
        l5.style.transitionTimingFunction="ease-in";
        l5.style.color="white";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="X TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});

l6.addEventListener("click",function(){
	
	var block=l6.getAttribute("Id");
	if(turnp1==0
)
	{
		l6.textContent="X";
		l6.style.transition="0.6s";
        l6.style.fontSize=" 90px";
        l6.style.fontStyle="Bold";
  		l6.style.objectFit="cover";
  		l6.style.color="white";
        l6.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="O TURN";
		if(chance1>=3)
		{
			status1();

		}
		
	}
	else if(turnp2==0
)
	{   l6.textContent="O";
        l6.style.transition="0.5s";
        l6.style.fontSize=" 90px";
        l6.style.fontStyle="Bold";
  		l6.style.objectFit="cover";
  		l6.style.color="white";
  		
  	
        l6.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="X TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});
l7.addEventListener("click",function(){
	
	var block=l7.getAttribute("Id");
	if(turnp1==0
)
	{
		l7.textContent="X";
		l7.style.transition="0.6s";
        l7.style.fontSize=" 90px";
        l7.style.fontStyle="Bold";
  		l7.style.objectFit="cover";
  		l7.style.color="white";
        l7.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="O TURN";
		if(chance1>=3)
		{
			status1();

		}
		
		
	}
	else if(turnp2==0)
	{    l7.textContent="O";

        l7.style.transition="0.5s";
        l7.style.fontSize=" 90px";
        l7.style.fontStyle="Bold";
  		l7.style.objectFit="cover";
  		l7.style.color="white";
  		
  	
        l7.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="X TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});
l8.addEventListener("click",function(){
	
	var block=l8.getAttribute("Id");
	if(turnp1==0
)
	{
		l8.textContent="X";
		l8.style.transition="0.6s";
        l8.style.fontSize=" 90px";
        l8.style.fontStyle="Bold";
  		l8.style.objectFit="cover";
  		l8.style.color="white";
        l8.style.transitionTimingFunction="ease-in";
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="O TURN";
		if(chance1>=3)
		{
			status1();

		}
		
	}
	else if(turnp2==0
)
	{   l8.textContent="O";
        l8.style.transition="0.5s";
        l8.style.fontSize=" 90px";
        l8.style.fontStyle="Bold";
  		l8.style.objectFit="cover";
  		l8.style.color="white";
  		
  	
        l8.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="X TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




});
l9.addEventListener("click",function(){
	
	var block=l9.getAttribute("Id");
	if(turnp1==0)
	{
		l9.textContent="X";
		l9.style.transition="0.6s";
        l9.style.fontSize=" 90px";
        l9.style.fontStyle="Bold";
  		l9.style.objectFit="cover";
  		l9.style.color="white";
        l9.style.transitionTimingFunction="ease-in";
       
		player1[chance1]=block;
		turnp2="0";
		turnp1="1";
		chance1=chance1+1;
		turndisplay.textContent="O TURN";
		if(chance1>=3)
		{
			status1();

		}
		
	}
	else if(turnp2==0)
	{   l9.textContent="O";
        l9.style.transition="0.5s";
        l9.style.fontSize=" 90px";
        l9.style.fontStyle="Bold";
  		l9.style.objectFit="cover";
  		l9.style.color="white";
  	
        l9.style.transitionTimingFunction="ease-in";
		player2[chance2]=block;
		turnp2="1";
		turnp1="0";
		chance2=chance2+1;
		turndisplay.textContent="X TURN";
		if (chance2>=3)
		{
			player2();

		}
	}
	
	




  });
function status1(){
   for(var m=0;m<chance1;m++)
  {
  		sort[m]=player1[m];
  }
  	
  	 
	
	for(var k=0;k<chance1;k++)
	{
       for(var m=k+1;m<chance1;m++)
       {
       	if(sort[k]>sort[m])
       	{
       		temp=sort[k];
       		sort[k]=sort[m];
       		sort[m]=temp;

       	}
       }
	}
	for(var n=0;n<chance1-2;n++)
    {	
  	  if((sort[n+1]-sort[n])==(sort[n+2]-sort[n+1]))
  	  {      
             starting=sort[n];
             starting2=sort[n+1]
             starting3=sort[n+2];
             setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);
             
             $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 1 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
             
              
             // $("#showcase").fadeOut(1000,function(){
              	//$('#showcase').replaceWith("<h2>PLAYER 1 WON</h2>");
              	//$("h2").css("margin-left","40%");
              	//$("h2").css("transform","scale(1.01)");
              	//$("#showcase").fadeIn("slow");
             

              //});
              

             
            
             
  	  }
}
         for(var p=0;p<chance1;p++)
    {
    	for(var q=p+1;q<chance1;q++)
    	{
    		if(2*(sort[q]-sort[p])==sort[q+2]-sort[p])
    		{    starting=sort[p];
                            starting2=sort[p+1];
                            starting3=sort[p+3];
                             setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);
    			$('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 1 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
    			}
    		}
    	}
    	for(var r=0;r<chance1;r++)
     {
     	for(var e=r+2;e<chance1;e++)
     	{
     		if(2*(sort[e]-sort[r])==sort[e+1]-sort[r])
     		{       starting=sort[r];
                            starting2=sort[r+2];
                            starting3=sort[r+3];

     		 setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);
                    $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 1 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
     		}
     	}
     }
     if(chance1==5)
{
  	 $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "AAAHH!",
  text: "MATCH DRAWN",
  icon: "warning",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
}


   }
   function player2()
   {
   	for(i=0;i<chance2;i++)
   	{
   		sort2[i]=player2[i];

   	}
   	for(var k=0;k<chance2;k++)
	{
       for(var m=k+1;m<chance2;m++)
       {
       	if(sort2[k]>sort2[m])
       	{
       		temp=sort2[k];
       		sort2[k]=sort2[m];
       		sort2[m]=temp;

       	}
       }
	}
	for(var n=0;n<chance2-2;n++)
    {	
  	  if((sort2[n+1]-sort2[n])==(sort2[n+2]-sort2[n+1]))
  	  {      
             starting=sort2[n];
             starting2=sort2[n+1]
             starting3=sort2[n+2];
             setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);
             
             $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 2 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
             
              
             // $("#showcase").fadeOut(1000,function(){
              	//$('#showcase').replaceWith("<h2>PLAYER 1 WON</h2>");
              	//$("h2").css("margin-left","40%");
              	//$("h2").css("transform","scale(1.01)");
              	//$("#showcase").fadeIn("slow");
             

              //});
              

             
            
             
  	  }
}
         for(var p=0;p<chance2;p++)
    {
    	for(var q=p+1;q<chance2;q++)
    	{
    		if(2*(sort2[q]-sort2[p])==sort2[q+2]-sort2[p])
    		{    starting=sort2[p];
                            starting2=sort2[p+1];
                            starting3=sort2[p+3];
                             setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);

    			$('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 2 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
    			return;
    			}
    		}
    	}
    	for(var r=0;r<chance2;r++)
     {
     	for(var e=r+2;e<chance2;e++)
     	{
     		if(2*(sort2[e]-sort2[r])==sort2[e+1]-sort2[r])
     		{    starting=sort2[r];
                            starting2=sort2[r+2];
                            starting3=sort2[r+3];
                            setTimeout(function(){
             	for(i=4;i<13;i++)
             {
             	if(starting==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting2==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             	else if(starting3==buttonid[i].getAttribute("Id"))
             	{
             		buttonid[i].style.backgroundColor="#74eb34";
             	}
             }
         },8);
                  $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "BINGO!",
  text: "PLAYER 2 WON",
  icon: "success",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
     		}
     	}
     }

   }

if(chance2==5)
{
  	 $('#turn').fadeOut(1800);
              $('#showcase').fadeOut(1800);

             setTimeout(function() { swal({
  title: "AAAHH!",
  text: "MATCH DRAWN",
  icon: "warning",
  button:false,
}); }, 1900);
             setTimeout(function(){window.open("Tic Tac Toe.html","_self");},4500);
}

		

		


	
	console.log(signp2);
});	



});
