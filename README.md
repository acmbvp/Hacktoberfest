# Hacktoberfest

# Instructions :

#### 1. Fork the Repository
###### You can fork this repository on GitHub by navigating at the top of this repository.

###### GitHub repository URLs will reference both the username associated with the owner of the repository, as well as the repository name. For example, acmbvp is the owner of the hacktoberfest repository, so the GitHub URL for this project is: 

https://github.com/acmbvp/Hacktoberfest/

###### When you’re on the main page for the repository, you’ll see a “Fork” button on your upper right-hand side of the page, underneath your user icon:

#### 2. Clone the Repository

###### To make your own local copy of the repository you would like to contribute to, let’s first open up a terminal window.

###### We’ll use the // git clone //  command along with the URL that points to your fork of the repository.

###### This URL will be similar to the URL above, except now it will end with // .git.// In the cloud_haiku example above, the URL will look like this:
https://github.com/your-username/Hacktoberfest.git

###### You can alternatively copy the URL by using the green “Clone or download” button from your repository page that you just forked from the original repository page. Once you click the button, you’ll be able to copy the URL by clicking the binder button next to the URL:
photo
###### Once we have the URL, we’re ready to clone the repository. To do this, we’ll combine the git clone command with the repository URL from the command line in a terminal window:

git clone https://github.com/your-username/Hacktoberfest.git

#### 3. Create a New Branch

###### To create your branch, from your terminal window, change your directory so that you are working in the directory of the repository. Be sure to use the actual name of the repository (i.e. Hacktoberfest) to change into that directory.

##### cd Hacktoberfest

###### Now, we’ll create our new branch with the git branch command. Make sure you name it descriptively so that others working on the project understand what you are working on.

##### git branch new-branch

###### Now that our new branch is created, we can switch to make sure that we are working on that branch by using the git checkout command:

##### git checkout new-branch

