<?php

/*Function ouputs the header for the page and opening of the body tag*/
function outputHeader($title){
    echo '<!DOCTYPE html>';
    echo '<html>';
    echo '<head>';
    echo '<!-- Page title -->';
    echo '<title>' . $title . '</title>';
    echo '<!-- Meta tag that specifies character set that this website written with -->';
    echo '<meta charset="UTF-8">';
    echo '<!-- Linking CSS page to this page -->';
    echo '<link rel="stylesheet" type="text/css" href="styles.css">';
    echo '<link href="style.css" type="text/css" rel="stylesheet">';
    echo '</head>';
    echo '<body>';
}

/* Ouputs the banner and the navigation bar. The selected class is applied to the page that matches the page name variable */
function outputBannerNavigation($pageName){
    /*Output banner and first part of navigation*/
    echo '<!-- logo -->';
    echo '<img id="logo" src="images/logo.png" alt="logo">';
    echo '<!-- Navigation bar -->';
    echo '<ul class="nav">';
        
    /*Array of pages to link to*/
    $linkNames = array("HOME","LOGIN/REGISTER","SCOREBOARD");
    $linkAddresses =array("home.php","loginregister.php","scoreboard.php");

    /*Outputs navigation bar*/
    for($x = 0; $x < count($linkNames); $x++){
        echo '<li>';
        echo '<a ';
        if($linkNames[$x] == $pageName){
            echo 'class="current" ';
        }
        echo 'href="' . $linkAddresses[$x] . '">' . $linkNames[$x] . '</a>';
    }
    echo '</ul>';
}

/*Outputs footer, closing body tag and closing HTML tag*/
function outputFooter(){
    echo '<!-- Footer -->';
    echo '<div id="footer">';
    echo '<footer>';
    echo '<!-- Users can e-mail to designer directly by link -->';
    echo '<p>Copyright - Umut Ekerdiker <br>2017<br>E-mail me <a href="mailto:ue036@live.mdx.ac.uk"> here!</a></p>';
    echo '</footer>';
    echo '</div>';
    echo '</body>';
    echo '</html>';
}
?>