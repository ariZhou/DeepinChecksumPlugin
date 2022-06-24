安装：
1.使用Qt编译得到可执行文件
2.在主目录下创建.hash文件夹，将可执行文件放入该文件夹。或是修改dtkHash.desktop中的路径
3.将.desktop文件放入deepin的插件管理文件夹，该文件夹详见 https://github.com/martyr-deepin/dde-file-manager-menu-oem


项目背景：
我使用的是win+deepin的双系统。在使用deepin时有过一段时间需要MD5对文件进行验证，但是在deepin系统上获得MD5不太方便。因为需要去商店下载专门的工具，要不使用在线网页获得。以前使用win的时候，安装7zip后能够直接鼠标右键获得一些校验信息。可deepin现在还没有这样的功能，于是就萌生了自己移植该功能的想法。于是在参加deepin社区实习期间对这个想法进行了实现。

项目用途：
计算和显示文件的MD5、Sha1、Sha256校验码

未来展望：
在未来该程序能够支持任意文件与文件夹，将校验计算方式与7zip的计算过程相一致，并将该功能集成到deepin自带的压缩软件中。
