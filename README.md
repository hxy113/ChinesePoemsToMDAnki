# ChinesePoemsToMDAnki
一个将古诗文分句制作成卡片的程序。
需要结合[MDAnki](https://github.com/ashlinchak/mdanki)使用。
自带翻转卡片功能。
以QT C++开发。

## 安装MDAnki
>  比这个程序本身还重要！

下载[node.js](https://nodejs.org/zh-cn/download)安装，自带Node Package Manager亦即npm。（用镜像站cnpm也可以）
以管理员权限打开powershell。
首先使用 `Set-ExecutionPolicy RemoteSigned`，再输入 `Y`，允许安装脚本。
然后再使用 `npm config get prefix` 查看全局安装的包被安装到哪个目录。
（你可以使用 `npm config set prefix "D:\npm"` 更改全局安装目录到 `D:\npm`，其他位置亦类似）
将这个目录加入系统环境变量中的Path。
然后使用 `npm install -g mdanki` 安装MDAnki。
可以用这种方法测试是否顺利安装：打开 `cmd` 或 `powershell`，直接输入 `mdanki` 执行。如果出现了 `Convert Markdown file into anki's apkg file for importing` 等正常描述的话，代表安装成功。

## 安装

可以下载作者已经用[Enigma Virtual Box](Enigma Virtual Box)打包好的.exe直接运行。
也可以在本地用QT C++构建并运行。

## 用法

将古诗文粘贴到左侧的文本框。
下面三行：
- 分隔符
- 输出文件名
- 标签
均可以更改。
- 点击预览：会在右边的右侧文本框生成预览。
- 输出为.apkg文件：如果电脑上没有安装MDAnki请不要选择此项。
- 输出为.md文件：无特殊限制，需稍后用MDAnki手动转换。

后两个按钮点击后会弹出窗口，要求你选择文件将要保存到的目录。
