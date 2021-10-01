# Hacktoberfest

###### ⚠️ This repository is excluded from Hacktoberfest in favour of promoting quality open source contributions. So pull requests here won't contribute towards your Hacktoberfest progress. The sole purpose of this repository is to help beginners learn Git & GitHub through easy first contribution, and we therefore are still welcoming pull requests here.

## Instructions:

*Make sure you have a GitHub account. In case you don't have one, you can create your account by visiting https://github.com/ and clicking on ``Sign up`` option at the top right corner.*

### 1. Register yourself for Hacktoberfest
###### Link to register: https://hacktoberfest.digitalocean.com/
Click on "Start Hacking" and add your GitHub account.

![Screenshot-HFST](https://user-images.githubusercontent.com/22788214/66115214-0166c400-e5ee-11e9-9659-1ef73e30e2b5.png)



### 2. Star and Fork this Repository
###### You can star and fork this repository on GitHub by navigating at the top of this repository.

GitHub repository URLs will reference both the username associated with the owner of the repository, as well as the repository name. For example, acmbvp is the owner of the Hacktoberfest repository, so the GitHub URL for this project is:

https://github.com/acmbvp/Hacktoberfest/


![screenshot-star](https://user-images.githubusercontent.com/37223446/47229499-79d87300-d3e5-11e8-9f2f-84e0d49e0439.png)

![screenshot-fork](https://user-images.githubusercontent.com/37223446/47229495-77761900-d3e5-11e8-9de0-1891f5f7b245.png)

When you’re on the main page of a repository, you’ll see a button to "Star" and “Fork” the repository on the upper right-hand side of the page, underneath your user icon.

### 3. Clone the Repository

To make your own local copy of the repository you would like to contribute to, let’s first open up a terminal window.

We’ll use the `git clone`  command along with the URL that points to your fork of the repository.

This URL will be similar to the URL above, except now it will end with `.git.` In the cloud_haiku example above, the URL will look like this:
https://github.com/your-username/Hacktoberfest.git

You can alternatively copy the URL by using the green “Clone or download” button from your repository page that you just forked from the original repository page. Once you click the button, you’ll be able to copy the URL by clicking the binder button next to the URL:

![screenshot 73](https://user-images.githubusercontent.com/37223446/47234826-b495d780-d3f4-11e8-9077-859ed9078677.png)

Once we have the URL, we’re ready to clone the repository. To do this, we’ll combine the git clone command with the repository URL from the command line in a terminal window:

`git clone https://github.com/your-username/Hacktoberfest.git`

![screenshot 153](https://user-images.githubusercontent.com/37223446/47234624-0f7aff00-d3f4-11e8-81c4-9198e3e83860.png)

### 4. Create a New Branch

To create your branch, from your terminal window, change your directory so that you are working in the directory of the repository. Be sure to use the actual name of the repository (i.e. Hacktoberfest) to switch into that directory.

#####    `cd Hacktoberfest`

Now, we’ll create our new branch with the git branch command. Make sure you name it descriptively so that others working on the project understand what you are working on.

![screenshot 154](https://user-images.githubusercontent.com/37223446/47234964-240bc700-d3f5-11e8-9837-50685ad44382.png)

##### `git branch new-branch`

Now that our new branch is created, we can switch to make sure that we are working on that branch by using the git checkout command:

##### ` git checkout new-branch `

Once you enter the git `checkout` command, you will receive the following output:

######  `Output:`
#####  `Switched to branch 'new-branch' `


At this point, you can now modify existing files or add new files to the project on your own branch.

#### Make Changes Locally

Once you have modified existing files or added new files to the project, you can add them to your local repository, which you can do with the git add command. Let’s add the -A flag to add all changes that we have made:

##### ` git add -A ` or ` git add . `

![screenshot 155](https://user-images.githubusercontent.com/37223446/47253493-417e7680-d471-11e8-83cf-a4f969da5131.png)


Next, we’ll want to record the changes that we made to the repository with the git commit command.

*The commit message is an important aspect of your code contribution; it helps the other contributors fully understand the change you have made, why you made it, and how significant it is. Additionally, commit messages provide a historical record of the changes for the project at large, helping future contributors along the way.*


![screenshot 155](https://user-images.githubusercontent.com/37223446/47235390-87e2bf80-d3f6-11e8-81c0-e01b7463d038.png)

If you have a very short message, you can record that with the -m flag and the message in quotes:

###### ` Example: `
##### ` git commit -m "Updated Readme.md" `

![screenshot 156](https://user-images.githubusercontent.com/37223446/47235961-3fc49c80-d3f8-11e8-906f-a1cfa7a15726.png)


###### At this point you can use the git push command to push the changes to the current branch of your forked repository:
###### ` Example:`
##### ` git push --set-upstream origin new-branch `

### 5. Update Local Repository

*While working on a project alongside other contributors, it is important for you to keep your local repository up-to-date with the project as you don’t want to make a pull request for code that will cause conflicts. To keep your local copy of the code base updated, you’ll need to sync changes.*

We’ll first go over configuring a remote for the fork, then syncing the fork.

### 6. Configure a Remote for the Fork

Next up, you’ll have to specify a new remote upstream repository for us to sync with the fork. This will be the original repository that you forked from. you’ll have to do this with the git remote add command.

##### ` git remote add upstream https://github.com/acmbvp/Hacktoberfest.git `


![screenshot 74](https://user-images.githubusercontent.com/37223446/47235672-5f0efa00-d3f7-11e8-9e45-1af02d8b969b.png)

In this example, // upstream // is the shortname we have supplied for the remote repository since in terms of Git, “upstream” refers to the repository that you cloned from. If you want to add a remote pointer to the repository of a collaborator, you may want to provide that collaborator’s username or a shortened nickname for the shortname.

### 7. Sync the Fork

Once you have configured a remote that references the upstream and original repository on GitHub, you are ready to sync your fork of the repository to keep it up-to-date.
To sync your fork, from the directory of your local repository in a terminal window, you’ll have to use the // git fetch // command to fetch the branches along with their respective commits from the upstream repository. Since you used the shortname “upstream” to refer to the upstream repository, you’ll have to pass that to the command:

##### ` git fetch upstream `

Switch to the local master branch of our repository:

##### ` git checkout master `

Now merge any changes that were made in the original repository’s master branch, that you will access through your local upstream/master branch, with your local master branch:

##### ` git merge upstream/master `

### 8. Create Pull Request

At this point, you are ready to make a pull request to the original repository.

Navigate to your forked repository, and press the “New pull request” button on your left-hand side of your Repo page.

# Hurray! You just got closer to completing your Hacktoberfest challenge.

> ©ACM-BVP 2019
I m new to opensource
