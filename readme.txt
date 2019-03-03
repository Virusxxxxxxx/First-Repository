git is a great tool.
I'm the new.
It's the second time;

添加
git add <文件名.后缀>
git commit -m "备注内容"

git status  //工作区提交状态

git log		//提交日志

git reset --hard HEAD^ 	//返回上一个版本，几个^返回几个版本
git reset --hard <版本号>	//返回指定版本号

git reflog		//查看命令历史（从旧版本回到新版本）

git rm <文件名.后缀>
git commit -m "内容"	//删除仓库文件

git checkout -- <文件名.后缀>		//找回删除的文件

git push origin master 		//把本地最新修改推送到GitHub