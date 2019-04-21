<?php
    /*Include the PHP functions to be used on the page*/
    include('common.php'); 
	
    //Output header and navigation 
    outputHeader("Welcome to DoGGBall - Scoreboard");
    outputBannerNavigation("HOME");
?>

 <!-- Scoreboard table-->
        <div id="scoreboard">
           <table>
                <tr>
                    <!-- table header -->
                    <th>USERNAME</th>
                    <!-- table header -->
                    <th>SCORE</th>
               </tr>
               <tr>
                   <td>BIGGIE SMALLS</td>
                   <td>248</td>
               </tr>
               <tr>
                   <td>DEATHBUNNY</td>
                   <td>224</td>
               </tr>
               <tr>
                   <td>A$AP ROCKY</td>
                   <td>209</td>
               </tr>
               <tr>
                    <td>SKEPPY</td>
                   <td>197</td>
               </tr>
               <tr>
                   <td>WRETCH 32</td>
                   <td>145</td>
               </tr>
            </table>
        </div>

<?php
    //Output the footer
    outputFooter();
?>