# 源文件说明
Builded with Eclipse integrated with Tomcat.  
Servlet和依赖类位于src/main/java中  
web中是简单的页面和jqury框架  
web.xml中不包含servlet信息，因为在servlet中通过注解标注了  

功能说明：可以通过页面发送ajax请求了，输入一本书名在数据库中查询相关书籍的数目是多少，并且servlet是可以返回json数据的，不过暂时不知道如何在前端进行json格式化，因此把返回json数据的相关功能注释掉了  