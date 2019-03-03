//添加文件
git add <文件名.后缀>
git commit -m "备注内容"

git status  //工作区提交状态

git log		//提交日志

git reset --hard HEAD^ 	//返回上一个版本，几个^返回几个版本
git reset --hard <版本号>	//返回指定版本号

//查看命令历史（从旧版本回到新版本）
git reflog

//删除仓库文件
git rm <文件名.后缀>
git commit -m "内容"	

//找回删除的文件
git checkout -- <文件名.后缀>		

//连接仓库
git remote add origin git@github.com:Virusxxxxxxx/Qt.git

//把本地最新修改推送到GitHub
git push origin master 		

//rm删除操作
git rm --cached <文件路径>	//仅将该文件从缓存中删除
git rm --f <文件路径>		//从缓存和本地删除

//删除github上仓库里的文件夹
git pull origin master			//将远程仓库里面的项目拉下来
dir								//查看有哪些文件夹
git rm -r --cached Photo\ albums  //删除Photo albums文件夹(文件夹名有空格命令行需要用"\ "来拼接）
git commit -m "内容"
git push -u origin master		//上传服务器

//修改远程仓库
git remote rm origin		//删除远程git仓库
git remote add origin git@github.com:Virusxxxxxxx/Qt.git	//再添加