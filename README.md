## 编译动态库
#### 单文件编译动态库
```
➜ clang -dynamiclib libmymath1.c libmymath2.c -o libmymath.dylib -current_version 1.0 -compatibility_version 1.0
```

#### 多文件编译动态库
```
➜ clang -dynamiclib libmymath.c -o libmymath1.dylib -current_version 1.0 -compatibility_version 1.0
```

#### 引用动态库进行编译
```
➜ clang app.c -o app libmymath.dylib
```

## 注入动态库
#### 编译注入的动态库
```
➜ clang -dynamiclib inject.c -o inject.dylib -current_version 1.0 -compatibility_version 1.0
```

#### 编译程序
```
➜ clang Program.c -o Program ; ./Program
Calling original function!
The number is: 5
warning: this program uses gets(), which is unsafe.
请输入密码：123
123
```

#### DYLD_INSERT_LIBRARIES 注入
```
➜ DYLD_INSERT_LIBRARIES=inject.dylib ./Program
Hello from dylib!
Calling original function!
The number is: 5
warning: this program uses gets(), which is unsafe.
请输入密码：123
123
```

#### 持久化注入
```
➜ yololib Program inject.dylib
2020-11-08 22:04:35.916 yololib[68420:1421499] dylib path @executable_path/inject.dylib
2020-11-08 22:04:35.919 yololib[68420:1421499] dylib path @executable_path/inject.dylib
Reading binary: Program

2020-11-08 22:04:35.920 yololib[68420:1421499] Thin 64bit binary!
2020-11-08 22:04:35.920 yololib[68420:1421499] dylib size wow 56
2020-11-08 22:04:35.920 yololib[68420:1421499] mach.ncmds 16
2020-11-08 22:04:35.921 yololib[68420:1421499] mach.ncmds 17
2020-11-08 22:04:35.921 yololib[68420:1421499] Patching mach_header..
2020-11-08 22:04:35.922 yololib[68420:1421499] Attaching dylib..

2020-11-08 22:04:35.922 yololib[68420:1421499] size 53
2020-11-08 22:04:35.922 yololib[68420:1421499] complete!
```

#### 查看引用库
```
➜ otool -L Program
Program:
	/usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1281.100.1)
	@executable_path/inject.dylib (compatibility version 1.0.0, current version 1.0.0)
```

#### 修改动态库加载路径
```
➜ mkdir -p Frameworks/Watch.framework
➜ cp inject.dylib Frameworks/Watch.framework/Watch

➜ otool -L Program
Program:
	/usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1281.100.1)
	@executable_path/inject.dylib (compatibility version 1.0.0, current version 1.0.0)

➜ install_name_tool -change @executable_path/inject.dylib @executable_path/Frameworks/Watch.framework/Watch Program

➜ otool -L Program
Program:
	/usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1281.100.1)
	@executable_path/Frameworks/Watch.framework/Watch (compatibility version 1.0.0, current version 1.0.0)
```

#### 参考资料
[Create C Program with Dynamic Library using Command Line in Mac OS X](https://www.zealfortechnology.com/2013/09/create-c-program-dynamic-library-command-line-mac-os-x.html)  
[Hooking C Functions at Runtime](http://thomasfinch.me/blog/2015/07/24/Hooking-C-Functions-At-Runtime.html)  
[Simple code injection using DYLD_INSERT_LIBRARIES](https://blog.timac.org/2012/1218-simple-code-injection-using-dyld_insert_libraries/https://blog.timac.org/2012/1218-simple-code-injection-using-dyld_insert_libraries/)  
[Tyilo/insert_dylib](https://github.com/Tyilo/insert_dylib)  
[DYLD_INSERT_LIBRARIES DYLIB injection in macOS / OSX](https://theevilbit.github.io/posts/dyld_insert_libraries_dylib_injection_in_macos_osx_deep_dive/)  
[如何注入mac os app](https://www.jianshu.com/p/6821d8d06c65)  