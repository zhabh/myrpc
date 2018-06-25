@echo off
::.\protoc.exe -I=E:\crucis_proto.git\proto --cpp_out=E:\crucis_proto.git\proto E:\crucis_proto.g
::it\proto\server.proto

set CS_CODE_DIR=.\cppcode
set CS_COMPILER_PATH=.\tool\protoc.exe
set CS_TARGET_PATH=..\source\services
  
  
::生成proto文件和rpc service代码
::自行修改--import后的绝对路径

if exist ".\tool\CppGenerator.exe" (
start  /D ".\tool" CppGenerator.exe --import=E:\\crucis_engine\\crucis_proto\\tools\\tool\\CofProtoDesc.dll
) else ( 
echo error:cant find CppGenerator.exe,please complier proto_auto!
) 


:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

::遍历所有文件
 ::1
 set SOURCE_FOLDER=.\proto
 set CS_OUTCPP_PATH=.\cppcode
if not exist %CS_OUTCPP_PATH% (
md %CS_OUTCPP_PATH%
) 
 for /f "delims=" %%i in ('dir /b "%SOURCE_FOLDER%\*.proto"') do (
     
     echo %CS_COMPILER_PATH% -I=%SOURCE_FOLDER% --cpp_out=%CS_OUTCPP_PATH% %%i
     %CS_COMPILER_PATH% -I=%SOURCE_FOLDER% --cpp_out=%CS_OUTCPP_PATH% %%i
	 
 )
 

 ::2 
set SOURCE_FOLDER=.\proto\crucis
 set CS_OUTCPP_PATH=.\cppcode\crucis
if not exist %CS_OUTCPP_PATH% (
md %CS_OUTCPP_PATH%
) 
  for /f "delims=" %%i in ('dir /b "%SOURCE_FOLDER%\*.proto"') do (
     
     echo %CS_COMPILER_PATH% -I=%SOURCE_FOLDER% --cpp_out=%CS_OUTCPP_PATH% %%i
     %CS_COMPILER_PATH% -I=%SOURCE_FOLDER% --cpp_out=%CS_OUTCPP_PATH% %%i
 )
 
 
 echo make success.
 
 xcopy  "%CS_CODE_DIR%" %CS_TARGET_PATH% /s /e /y
 
pause
