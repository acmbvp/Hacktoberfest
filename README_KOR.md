# Hacktoberfest

###### ⚠️ 이 저장소는 양질의 오픈 소스 기여를 홍보하기 위해 Hacktoberfest에서 제외됩니다. 따라서 여기에서의 pull 요청은 Hacktoberfest 진행에 기여하지 않습니다. 이 리포지토리의 유일한 목적은 초보자가 쉬운 첫 번째 기여를 통해 Git 및 GitHub를 배울 수 있도록 돕는 것이므로 여기에서 여전히 pull 요청을 환영합니다.

## 지침:

*GitHub 계정이 있어야 합니다. 계정이 없는 경우 https://github.com/을 방문하여 오른쪽 상단의 ``Sign up`` 옵션을 클릭하여 계정을 만들 수 있습니다.*


### 1. hacktoberfest에 등록하십시오.
###### 등록 링크: https://hacktoberfest.digitalocean.com/

"Start Hacking"을 누르고, 깃허브 아이디를 추가하세요. 

![Screenshot-HFST](https://user-images.githubusercontent.com/22788214/66115214-0166c400-e5ee-11e9-9659-1ef73e30e2b5.png)



### 2. Star와 저장소 fork하기
###### 이 저장소의 맨 위에서 Github에 있는 이 저장소를 fork하고, 별표할 수 있습니다. 

GitHub 저장소 URL은 저장소 소유자의 username과  저장소 이름을 모두 참조합니다.예를 들어 acmbvp는 Hacktoberfest 저장소의 오너이므로, 이 프로젝트의  GitHub URL은 이렇게 됩니다:
 
https://github.com/acmbvp/Hacktoberfest/


![screenshot-star](https://user-images.githubusercontent.com/37223446/47229499-79d87300-d3e5-11e8-9f2f-84e0d49e0439.png)

![screenshot-fork](https://user-images.githubusercontent.com/37223446/47229495-77761900-d3e5-11e8-9de0-1891f5f7b245.png)


저장소의 메인페이지에 있을때, 페이지의 우측 상단에서 유저 아이콘 아래에 있는 "Fork" 와 "Star"버튼을 볼 수 있을 겁니다. 

### 3. 레포지토리 복제하기

기여하고싶은 저장소에 대한 당신 소유의 로컬 복사본을 만들기 위해, 먼저 터니멀 창을 엽니다. 

fork한 저장소를 가리키는 URL과 함께 `git clone` 명령을 사용합니다.

이 URL은 `.git`으로 끝나는 점을 제외하면 위의 URL과 유사합니다. 위의 cloud_haiku 예시에서 URL은 다음과 같습니다.

https://github.com/your-username/Hacktoberfest.git

대안으로 원본 저장소에서 분기한 당신의 저장소에서 녹색의 "Clone or download"을 사용해 URL을 복사할 수 있습니다. 버튼을 누르면, URL 옆에 있는 바인더 클릭해서 URL을 복사할 수 있습니다.

![screenshot 73](https://user-images.githubusercontent.com/37223446/47234826-b495d780-d3f4-11e8-9077-859ed9078677.png)

일단 이 URL을 찾았다면, 이를 위해 터미널 창의 명령줄에 git clone 명령과 저장소 URL을 입력합니다.

`git clone https://github.com/your-username/Hacktoberfest.git`

![screenshot 153](https://user-images.githubusercontent.com/37223446/47234624-0f7aff00-d3f4-11e8-81c4-9198e3e83860.png)

### 4. 새로운 브렌치 만들기

 터미널 창에서 분기를 생성하기 위해서는, 워킹디렉터리를 저장소에 대한 디렉토리로 바꿔야합니다. 해당 디렉토리로 전환하려면 저장소의 실제 이름(즉, Hacktoberfest)을 사용해야 합니다.
##### `cd Hacktoberfest`

이제, git branch 명령어를 이용해서 새로운 브랜치를 만들어 볼 겁니다. 프로젝트를 함께하는 다른 사람들이 당신이 무엇을 하고있는지 알 수 있도록 설명이 포함된 이름으로 만들어야합니다.  

![screenshot 154](https://user-images.githubusercontent.com/37223446/47234964-240bc700-d3f5-11e8-9837-50685ad44382.png)

##### `git branch new-branch`

이제 새로운 브랜치를 만들었으므로, git chekcout 명령을 사용하여 해당 브랜치에서 작업중인지 확인하고 전환할 수 있습니다. 
##### ` git checkout new-branch `


git `checkout` 명령을 입력하면, 다음과 같은 출력을 받을 것입니다.:

######  `Output:`
#####  `Switched to branch 'new-branch' `


이제 기존 파일들을 수정하거나 자신의 브랜치에있는 프로젝트에 파일을 추가할 수 있습니다.
#### 로컬환경에서 변경하기 

기존 파일을 수정하거나 새로운 파일을 프로젝트에 추가한 후에 git add 명령을 이용해 로컬 저장소에 추가할 수 있습니다. -A를 추가해 만든 모든 변경사항을 추가해 보겠습니다.
##### ` git add -A ` or ` git add . `

![screenshot 155](https://user-images.githubusercontent.com/37223446/47253493-417e7680-d471-11e8-83cf-a4f969da5131.png)


다음으로, git commit 명령을 사용하여 저장소에 대한 변경사항을 기록하려고 합니다. 

*commit 메시지는 코드기여에서 중요합니다. 이는 다른 기여자들이 당신이 만든 변화에 대해, 왜 그것을 만들었는지, 그리고 얼마나 중요한지를 완전히 이해할 수 있도록 돕습니다. 추가적으로 커밋 메시지는 대규모 프로젝트에 대한 역사적 기록을 제공해, 향후 컨트리뷰터들에게 도움이 됩니다.*


![screenshot 155](https://user-images.githubusercontent.com/37223446/47235390-87e2bf80-d3f6-11e8-81c0-e01b7463d038.png)

만약 매우 짧은 메시지지라면, -m 플래그와 따옴표로 묵은 메시지로 기록할 수 있습니다. 
###### `예시`
##### ` git commit -m "Updated Readme.md" `


![screenshot 156](https://user-images.githubusercontent.com/37223446/47235961-3fc49c80-d3f8-11e8-906f-a1cfa7a15726.png)

###### 이 시점에서 변경사항을 fork한 저장소의 현재 브랜치에 푸시하기 위해 git push 명령을 사용할 수 있습니다. 


###### `예시`
##### ` git push --set-upstream origin new-branch `

### 5. 로컬저장소 업데이트

*다른 기역자들과 함께 프로젝트를 진행하는 동안, 충돌을 일으키는 코드에 대한 pull reqeust를 만들지 않기 위해 프로젝트에 대한 로컬 저장소를 최신으로 유지하는것은 중요합니다. 업데이트 된 로컬 복사본을 유지하기 위해서, 변경사항을 동기화 해야합니다.*


먼저 fork에 대한 원격(저장소)을 구성하고, fork를 동기화하는 방법을 살펴보겠습니다 
### 6. fork에 대한 원격(저장소) 구성

다음으로 fork와 동기화해야 할 새 원격 업스트림 저장소를 지정해야합니다. 이 저장소는 당신이 fork한 원본 저장소입니다. git remote add 명령으로 이 작업을 수행해야 합니다.

##### ` git remote add upstream https://github.com/acmbvp/Hacktoberfest.git `


![screenshot 74](https://user-images.githubusercontent.com/37223446/47235672-5f0efa00-d3f7-11e8-9e45-1af02d8b969b.png)

이 예에서, // upstream // 은 Git의 용어로, 복제한 저장소를 나타내는 "upstream"에서 가져온 원격저장소에 대한 짧은 이름입니다. 만약 공동작업자의 저장소에 대한 원격 포인터를 추가하려면, 콜라보레이터의 usernmae이나 짧은이름에 대한 단축된 닉네임을 제공할 수 있습니다.
### 7. fork 저장소 동기화하기


Github에서 업스트림 및 원본 저장소를 참고하는 원격을 구성하고 나면, 포크된 저장소를 최신으로 유지할 준비가 된 것입니다. fork를 동기화 하기 위해, 윈도우창에서 로컬 저장소의 디렉토리에서, 브랜치를  //git fetch//명령을 사용해 upstream 저장소에서 각각의 커밋들과 브랜치들을 가져와야 합니다. upstream저장소를 나타내기위해 "upsteram"이라는 단축이름을 사용했으므로, 이를 명령에 전달해야합니다.

##### ` git fetch upstream `

저장소의 로컬 master 브랜치로 전환합니다.
##### ` git checkout master `

이제 로컬 upstream/mster 브랜치를 통해 액세스할 원본 저장소의 master 브랜치에서 변경된 사항을 로컬 master 브랜치와 병합합니다.
##### ` git merge upstream/master `

### 8. Pull request 만들기

이제 원본 저장소에 pull reqeust할 준비가 되었습니다.

fork한 저장소로 이동하고, 저장소 페이지의 왼쪽편에 있는 "New pull request"버튼을 클릭합니다.

# 만세! Hacktoberfest 챌린지를 완료했습니다!

> ©ACM-BVP 2019
