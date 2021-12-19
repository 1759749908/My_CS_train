00251000  push        ebp  
00251001  mov         ebp,esp  
00251003  push        ebx  
00251004  push        edi  
00251005  push        esi  
00251006  and         esp,0FFFFFFF8h  
00251009  sub         esp,5F0h  
0025100F  mov         esi,esp  
00251011  mov         dword ptr [esi+0Ch],ebp  
00251014  mov         eax,esp  
00251016  mov         dword ptr [esi+5DCh],eax  
0025101C  mov         dword ptr [esi+5E8h],0FFFFFFFFh  
00251026  lea         eax,[esi+5E0h]  
0025102C  mov         dword ptr [esi+5E4h],252C80h  
00251036  mov         ecx,dword ptr fs:[0]  
0025103D  mov         dword ptr [esi+5E0h],ecx  
00251043  mov         dword ptr fs:[00000000h],eax  
00251049  mov         dword ptr [esi+5D8h],0  
00251053  lea         ecx,[esi+5C8h]  
	//cin.sync_with_stdio(false);
	vector<Book> library;
00251059  call        std::vector<Book,std::allocator<Book> >::vector (0252D60h)  
	library.emplace_back(Book("数学之美", 35, 275));
0025105E  mov         dword ptr [esi+594h],113h  
00251068  mov         dword ptr [esi+58Ch],40418000h  
00251072  mov         dword ptr [esi+588h],0  
0025107C  mov         dword ptr [esi+5E8h],0  
00251086  mov         eax,esp  
00251088  mov         dword ptr [eax],offset string "\xe6\x95\xb0\xe5\xad\xa6\xe4\xb9\x8b\xe7\xbe\x8e" (025B018h)  
0025108E  lea         ecx,[esi+56Ch]  
00251094  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string (0252E90h)  
00251099  sub         esp,4  
0025109C  jmp         main+0A1h (02510A1h)  
002510A1  mov         dword ptr [esi+5E8h],1Dh  
002510AB  mov         eax,esp  
002510AD  lea         ecx,[esi+594h]  
002510B3  mov         dword ptr [eax+8],ecx  
002510B6  lea         ecx,[esi+588h]  
002510BC  mov         dword ptr [eax+4],ecx  
002510BF  lea         ecx,[esi+56Ch]  
002510C5  mov         dword ptr [eax],ecx  
002510C7  lea         ecx,[esi+598h]  
002510CD  call        Book::Book (02520E0h)  
002510D2  sub         esp,0Ch  
002510D5  jmp         main+0DAh (02510DAh)  
002510DA  mov         dword ptr [esi+5E8h],1Eh  
002510E4  mov         eax,esp  
002510E6  lea         ecx,[esi+598h]  
002510EC  mov         dword ptr [eax],ecx  
002510EE  lea         ecx,[library]  
002510F4  call        std::vector<Book,std::allocator<Book> >::emplace_back<Book> (0252E10h)  
002510F9  sub         esp,4  
002510FC  jmp         main+101h (0251101h)  
00251101  lea         ecx,[esi+598h]  
00251107  call        Book::~Book (0252FC0h)  
0025110C  lea         ecx,[esi+56Ch]  
00251112  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
	library.emplace_back(Book("浪潮之巅", 39, 287));
00251117  mov         dword ptr [esi+534h],11Fh  
00251121  mov         dword ptr [esi+52Ch],40438000h  
0025112B  mov         dword ptr [esi+528h],0  
00251135  mov         dword ptr [esi+5E8h],0  
0025113F  mov         eax,esp  
00251141  mov         dword ptr [eax],offset string "\xe6\xb5\xaa\xe6\xbd\xae\xe4\xb9\x8b\xe5\xb7\x85" (025B025h)  
00251147  lea         ecx,[esi+50Ch]  
0025114D  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string (0252E90h)  
00251152  sub         esp,4  
00251155  jmp         main+15Ah (025115Ah)  
0025115A  mov         dword ptr [esi+5E8h],1Bh  
00251164  mov         eax,esp  
00251166  lea         ecx,[esi+534h]  
0025116C  mov         dword ptr [eax+8],ecx  
0025116F  lea         ecx,[esi+528h]  
00251175  mov         dword ptr [eax+4],ecx  
00251178  lea         ecx,[esi+50Ch]  
0025117E  mov         dword ptr [eax],ecx  
00251180  lea         ecx,[esi+538h]  
00251186  call        Book::Book (02520E0h)  
0025118B  sub         esp,0Ch  
0025118E  jmp         main+193h (0251193h)  
00251193  mov         dword ptr [esi+5E8h],1Ch  
0025119D  mov         eax,esp  
0025119F  lea         ecx,[esi+538h]  
002511A5  mov         dword ptr [eax],ecx  
002511A7  lea         ecx,[library]  
002511AD  call        std::vector<Book,std::allocator<Book> >::emplace_back<Book> (0252E10h)  
002511B2  sub         esp,4  
002511B5  jmp         main+1BAh (02511BAh)  
002511BA  lea         ecx,[esi+538h]  
002511C0  call        Book::~Book (0252FC0h)  
002511C5  lea         ecx,[esi+50Ch]  
002511CB  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
	library.emplace_back(Book("计算之魂", 55, 27));
002511D0  mov         dword ptr [esi+4D4h],1Bh  
002511DA  mov         dword ptr [esi+4CCh],404B8000h  
002511E4  mov         dword ptr [esi+4C8h],0  
002511EE  mov         dword ptr [esi+5E8h],0  
002511F8  mov         eax,esp  
002511FA  mov         dword ptr [eax],offset string "\xe8\xae\xa1\xe7\xae\x97\xe4\xb9\x8b\xe9\xad\x82" (025B032h)  
00251200  lea         ecx,[esi+4ACh]  
00251206  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string (0252E90h)  
0025120B  sub         esp,4  
0025120E  jmp         main+213h (0251213h)  
00251213  mov         dword ptr [esi+5E8h],19h  
0025121D  mov         eax,esp  
0025121F  lea         ecx,[esi+4D4h]  
00251225  mov         dword ptr [eax+8],ecx  
00251228  lea         ecx,[esi+4C8h]  
0025122E  mov         dword ptr [eax+4],ecx  
00251231  lea         ecx,[esi+4ACh]  
00251237  mov         dword ptr [eax],ecx  
00251239  lea         ecx,[esi+4D8h]  
0025123F  call        Book::Book (02520E0h)  
00251244  sub         esp,0Ch  
00251247  jmp         main+24Ch (025124Ch)  
0025124C  mov         dword ptr [esi+5E8h],1Ah  
00251256  mov         eax,esp  
00251258  lea         ecx,[esi+4D8h]  
0025125E  mov         dword ptr [eax],ecx  
00251260  lea         ecx,[library]  
00251266  call        std::vector<Book,std::allocator<Book> >::emplace_back<Book> (0252E10h)  
0025126B  sub         esp,4  
0025126E  jmp         main+273h (0251273h)  
00251273  lea         ecx,[esi+4D8h]  
00251279  call        Book::~Book (0252FC0h)  
0025127E  lea         ecx,[esi+4ACh]  
00251284  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
	library.emplace_back(Book("三国演义", 20, 685));
00251289  mov         dword ptr [esi+474h],2ADh  
00251293  mov         dword ptr [esi+46Ch],40340000h  
0025129D  mov         dword ptr [esi+468h],0  
002512A7  mov         dword ptr [esi+5E8h],0  
002512B1  mov         eax,esp  
002512B3  mov         dword ptr [eax],offset string "\xe4\xb8\x89\xe5\x9b\xbd\xe6\xbc\x94\xe4\xb9\x89" (025B03Fh)  
002512B9  lea         ecx,[esi+44Ch]  
002512BF  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string (0252E90h)  
002512C4  sub         esp,4  
002512C7  jmp         main+2CCh (02512CCh)  
002512CC  mov         dword ptr [esi+5E8h],17h  
002512D6  mov         eax,esp  
002512D8  lea         ecx,[esi+474h]  
002512DE  mov         dword ptr [eax+8],ecx  
002512E1  lea         ecx,[esi+468h]  
002512E7  mov         dword ptr [eax+4],ecx  
002512EA  lea         ecx,[esi+44Ch]  
002512F0  mov         dword ptr [eax],ecx  
002512F2  lea         ecx,[esi+478h]  
002512F8  call        Book::Book (02520E0h)  
002512FD  sub         esp,0Ch  
00251300  jmp         main+305h (0251305h)  
00251305  mov         dword ptr [esi+5E8h],18h  
0025130F  mov         eax,esp  
00251311  lea         ecx,[esi+478h]  
00251317  mov         dword ptr [eax],ecx  
00251319  lea         ecx,[library]  
0025131F  call        std::vector<Book,std::allocator<Book> >::emplace_back<Book> (0252E10h)  
00251324  sub         esp,4  
00251327  jmp         main+32Ch (025132Ch)  
0025132C  lea         ecx,[esi+478h]  
00251332  call        Book::~Book (0252FC0h)  
00251337  lea         ecx,[esi+44Ch]  
0025133D  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
	library.emplace_back(Book("五年单身，三年当狗", 10, 185));
00251342  mov         dword ptr [esi+414h],0B9h  
0025134C  mov         dword ptr [esi+40Ch],40240000h  
00251356  mov         dword ptr [esi+408h],0  
00251360  mov         dword ptr [esi+5E8h],0  
0025136A  mov         eax,esp  
0025136C  mov         dword ptr [eax],offset string "\xe4\xba\x94\xe5\xb9\xb4\xe5\x8d\x95\xe8\xba\xab\xef\xbc\x8c\xe4\xb8\x89\xe5\xb9\xb4\xe5\xbd\x93\xe7\x8b\x97" (025B04Ch)  
00251372  lea         ecx,[esi+3ECh]  
00251378  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string (0252E90h)  
0025137D  sub         esp,4  
00251380  jmp         main+385h (0251385h)  
00251385  mov         dword ptr [esi+5E8h],15h  
0025138F  mov         eax,esp  
00251391  lea         ecx,[esi+414h]  
00251397  mov         dword ptr [eax+8],ecx  
0025139A  lea         ecx,[esi+408h]  
002513A0  mov         dword ptr [eax+4],ecx  
002513A3  lea         ecx,[esi+3ECh]  
002513A9  mov         dword ptr [eax],ecx  
002513AB  lea         ecx,[esi+418h]  
002513B1  call        Book::Book (02520E0h)  
002513B6  sub         esp,0Ch  
002513B9  jmp         main+3BEh (02513BEh)  
002513BE  mov         dword ptr [esi+5E8h],16h  
002513C8  mov         eax,esp  
002513CA  lea         ecx,[esi+418h]  
002513D0  mov         dword ptr [eax],ecx  
002513D2  lea         ecx,[library]  
002513D8  call        std::vector<Book,std::allocator<Book> >::emplace_back<Book> (0252E10h)  
002513DD  sub         esp,4  
002513E0  jmp         main+3E5h (02513E5h)  
002513E5  lea         ecx,[esi+418h]  
002513EB  call        Book::~Book (0252FC0h)  
002513F0  lea         ecx,[esi+3ECh]  
002513F6  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
	library.emplace_back(Book("中国共产党简史", 20, 927));
002513FB  mov         dword ptr [esi+3B4h],39Fh  
00251405  mov         dword ptr [esi+3ACh],40340000h  
0025140F  mov         dword ptr [esi+3A8h],0  
00251419  mov         dword ptr [esi+5E8h],0  
00251423  mov         eax,esp  
00251425  mov         dword ptr [eax],offset string "\xe4\xb8\xad\xe5\x9b\xbd\xe5\x85\xb1\xe4\xba\xa7\xe5\x85\x9a\xe7\xae\x80\xe5\x8f\xb2" (025B068h)  
0025142B  lea         ecx,[esi+38Ch]  
00251431  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string (0252E90h)  
00251436  sub         esp,4  
00251439  jmp         main+43Eh (025143Eh)  
0025143E  mov         dword ptr [esi+5E8h],13h  
00251448  mov         eax,esp  
0025144A  lea         ecx,[esi+3B4h]  
00251450  mov         dword ptr [eax+8],ecx  
00251453  lea         ecx,[esi+3A8h]  
00251459  mov         dword ptr [eax+4],ecx  
0025145C  lea         ecx,[esi+38Ch]  
00251462  mov         dword ptr [eax],ecx  
00251464  lea         ecx,[esi+3B8h]  
0025146A  call        Book::Book (02520E0h)  
0025146F  sub         esp,0Ch  
00251472  jmp         main+477h (0251477h)  
00251477  mov         dword ptr [esi+5E8h],14h  
00251481  mov         eax,esp  
00251483  lea         ecx,[esi+3B8h]  
00251489  mov         dword ptr [eax],ecx  
0025148B  lea         ecx,[library]  
00251491  call        std::vector<Book,std::allocator<Book> >::emplace_back<Book> (0252E10h)  
00251496  sub         esp,4  
00251499  jmp         main+49Eh (025149Eh)  
0025149E  lea         ecx,[esi+3B8h]  
002514A4  call        Book::~Book (0252FC0h)  
002514A9  lea         ecx,[esi+38Ch]  
002514AF  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
	library.emplace_back(Book("文明之光", 30, 278));
002514B4  mov         dword ptr [esi+354h],116h  
002514BE  mov         dword ptr [esi+34Ch],403E0000h  
002514C8  mov         dword ptr [esi+348h],0  
002514D2  mov         dword ptr [esi+5E8h],0  
002514DC  mov         eax,esp  
002514DE  mov         dword ptr [eax],offset string "\xe6\x96\x87\xe6\x98\x8e\xe4\xb9\x8b\xe5\x85\x89" (025B07Eh)  
002514E4  lea         ecx,[esi+32Ch]  
002514EA  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string (0252E90h)  
002514EF  sub         esp,4  
002514F2  jmp         main+4F7h (02514F7h)  
002514F7  mov         dword ptr [esi+5E8h],11h  
00251501  mov         eax,esp  
00251503  lea         ecx,[esi+354h]  
00251509  mov         dword ptr [eax+8],ecx  
0025150C  lea         ecx,[esi+348h]  
00251512  mov         dword ptr [eax+4],ecx  
00251515  lea         ecx,[esi+32Ch]  
0025151B  mov         dword ptr [eax],ecx  
0025151D  lea         ecx,[esi+358h]  
00251523  call        Book::Book (02520E0h)  
00251528  sub         esp,0Ch  
0025152B  jmp         main+530h (0251530h)  
00251530  mov         dword ptr [esi+5E8h],12h  
0025153A  mov         eax,esp  
0025153C  lea         ecx,[esi+358h]  
00251542  mov         dword ptr [eax],ecx  
00251544  lea         ecx,[library]  
0025154A  call        std::vector<Book,std::allocator<Book> >::emplace_back<Book> (0252E10h)  
0025154F  sub         esp,4  
00251552  jmp         main+557h (0251557h)  
00251557  lea         ecx,[esi+358h]  
0025155D  call        Book::~Book (0252FC0h)  
00251562  lea         ecx,[esi+32Ch]  
00251568  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
	library.emplace_back(Book("编译系统", 60, 627));
0025156D  mov         dword ptr [esi+2F4h],273h  
00251577  mov         dword ptr [esi+2ECh],404E0000h  
00251581  mov         dword ptr [esi+2E8h],0  
0025158B  mov         dword ptr [esi+5E8h],0  
00251595  mov         eax,esp  
00251597  mov         dword ptr [eax],offset string "\xe7\xbc\x96\xe8\xaf\x91\xe7\xb3\xbb\xe7\xbb\x9f" (025B08Bh)  
0025159D  lea         ecx,[esi+2CCh]  
002515A3  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string (0252E90h)  
002515A8  sub         esp,4  
002515AB  jmp         main+5B0h (02515B0h)  
002515B0  mov         dword ptr [esi+5E8h],0Fh  
002515BA  mov         eax,esp  
002515BC  lea         ecx,[esi+2F4h]  
002515C2  mov         dword ptr [eax+8],ecx  
002515C5  lea         ecx,[esi+2E8h]  
002515CB  mov         dword ptr [eax+4],ecx  
002515CE  lea         ecx,[esi+2CCh]  
002515D4  mov         dword ptr [eax],ecx  
002515D6  lea         ecx,[esi+2F8h]  
002515DC  call        Book::Book (02520E0h)  
002515E1  sub         esp,0Ch  
002515E4  jmp         main+5E9h (02515E9h)  
002515E9  mov         dword ptr [esi+5E8h],10h  
002515F3  mov         eax,esp  
002515F5  lea         ecx,[esi+2F8h]  
002515FB  mov         dword ptr [eax],ecx  
002515FD  lea         ecx,[library]  
00251603  call        std::vector<Book,std::allocator<Book> >::emplace_back<Book> (0252E10h)  
00251608  sub         esp,4  
0025160B  jmp         main+610h (0251610h)  
00251610  lea         ecx,[esi+2F8h]  
00251616  call        Book::~Book (0252FC0h)  
0025161B  lea         ecx,[esi+2CCh]  
00251621  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
	library.emplace_back(Book("从一到无穷大", 40, 625));
00251626  mov         dword ptr [esi+294h],271h  
00251630  mov         dword ptr [esi+28Ch],40440000h  
0025163A  mov         dword ptr [esi+288h],0  
00251644  mov         dword ptr [esi+5E8h],0  
0025164E  mov         eax,esp  
00251650  mov         dword ptr [eax],offset string "\xe4\xbb\x8e\xe4\xb8\x80\xe5\x88\xb0\xe6\x97\xa0\xe7\xa9\xb7\xe5\xa4\xa7" (025B098h)  
00251656  lea         ecx,[esi+26Ch]  
0025165C  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string (0252E90h)  
00251661  sub         esp,4  
00251664  jmp         main+669h (0251669h)  
00251669  mov         dword ptr [esi+5E8h],0Dh  
00251673  mov         eax,esp  
00251675  lea         ecx,[esi+294h]  
0025167B  mov         dword ptr [eax+8],ecx  
0025167E  lea         ecx,[esi+288h]  
00251684  mov         dword ptr [eax+4],ecx  
00251687  lea         ecx,[esi+26Ch]  
0025168D  mov         dword ptr [eax],ecx  
0025168F  lea         ecx,[esi+298h]  
00251695  call        Book::Book (02520E0h)  
0025169A  sub         esp,0Ch  
0025169D  jmp         main+6A2h (02516A2h)  
002516A2  mov         dword ptr [esi+5E8h],0Eh  
002516AC  mov         eax,esp  
002516AE  lea         ecx,[esi+298h]  
002516B4  mov         dword ptr [eax],ecx  
002516B6  lea         ecx,[library]  
002516BC  call        std::vector<Book,std::allocator<Book> >::emplace_back<Book> (0252E10h)  
002516C1  sub         esp,4  
002516C4  jmp         main+6C9h (02516C9h)  
002516C9  lea         ecx,[esi+298h]  
002516CF  call        Book::~Book (0252FC0h)  
002516D4  lea         ecx,[esi+26Ch]  
002516DA  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
	library.emplace_back(Book("影响力", 40, 157));
002516DF  mov         dword ptr [esi+234h],9Dh  
002516E9  mov         dword ptr [esi+22Ch],40440000h  
002516F3  mov         dword ptr [esi+228h],0  
002516FD  mov         dword ptr [esi+5E8h],0  
00251707  mov         eax,esp  
00251709  mov         dword ptr [eax],offset string "\xe5\xbd\xb1\xe5\x93\x8d\xe5\x8a\x9b" (025B0ABh)  
0025170F  lea         ecx,[esi+20Ch]  
00251715  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string (0252E90h)  
0025171A  sub         esp,4  
0025171D  jmp         main+722h (0251722h)  
00251722  mov         dword ptr [esi+5E8h],0Bh  
0025172C  mov         eax,esp  
0025172E  lea         ecx,[esi+234h]  
00251734  mov         dword ptr [eax+8],ecx  
00251737  lea         ecx,[esi+228h]  
0025173D  mov         dword ptr [eax+4],ecx  
00251740  lea         ecx,[esi+20Ch]  
00251746  mov         dword ptr [eax],ecx  
00251748  lea         ecx,[esi+238h]  
0025174E  call        Book::Book (02520E0h)  
00251753  sub         esp,0Ch  
00251756  jmp         main+75Bh (025175Bh)  
0025175B  mov         dword ptr [esi+5E8h],0Ch  
00251765  mov         eax,esp  
00251767  lea         ecx,[esi+238h]  
0025176D  mov         dword ptr [eax],ecx  
0025176F  lea         ecx,[library]  
00251775  call        std::vector<Book,std::allocator<Book> >::emplace_back<Book> (0252E10h)  
0025177A  sub         esp,4  
0025177D  jmp         main+782h (0251782h)  
00251782  lea         ecx,[esi+238h]  
00251788  call        Book::~Book (0252FC0h)  
0025178D  lea         ecx,[esi+20Ch]  
00251793  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
	library.emplace_back(Book("C++从入门到放弃", 9.9, 278));
00251798  mov         dword ptr [esi+1D4h],116h  
002517A2  mov         dword ptr [esi+1CCh],4023CCCCh  
002517AC  mov         dword ptr [esi+1C8h],0CCCCCCCDh  
002517B6  mov         dword ptr [esi+5E8h],0  
002517C0  mov         eax,esp  
002517C2  mov         dword ptr [eax],offset string "C++\xe4\xbb\x8e\xe5\x85\xa5\xe9\x97\xa8\xe5\x88\xb0\xe6\x94\xbe\xe5\xbc\x83" (025B0B5h)  
002517C8  lea         ecx,[esi+1ACh]  
002517CE  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string (0252E90h)  
002517D3  sub         esp,4  
002517D6  jmp         main+7DBh (02517DBh)  
002517DB  mov         dword ptr [esi+5E8h],9  
002517E5  mov         eax,esp  
002517E7  lea         ecx,[esi+1D4h]  
002517ED  mov         dword ptr [eax+8],ecx  
002517F0  lea         ecx,[esi+1C8h]  
002517F6  mov         dword ptr [eax+4],ecx  
002517F9  lea         ecx,[esi+1ACh]  
002517FF  mov         dword ptr [eax],ecx  
00251801  lea         ecx,[esi+1D8h]  
00251807  call        Book::Book (02520E0h)  
0025180C  sub         esp,0Ch  
0025180F  jmp         main+814h (0251814h)  
00251814  mov         dword ptr [esi+5E8h],0Ah  
0025181E  mov         eax,esp  
00251820  lea         ecx,[esi+1D8h]  
00251826  mov         dword ptr [eax],ecx  
00251828  lea         ecx,[library]  
0025182E  call        std::vector<Book,std::allocator<Book> >::emplace_back<Book> (0252E10h)  
00251833  sub         esp,4  
00251836  jmp         main+83Bh (025183Bh)  
0025183B  lea         ecx,[esi+1D8h]  
00251841  call        Book::~Book (0252FC0h)  
00251846  lea         ecx,[esi+1ACh]  
0025184C  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
	library.emplace_back(Book("中华人民共和国刑法", 56, 378));
00251851  mov         dword ptr [esi+174h],17Ah  
0025185B  mov         dword ptr [esi+16Ch],404C0000h  
00251865  mov         dword ptr [esi+168h],0  
0025186F  mov         dword ptr [esi+5E8h],0  
00251879  mov         eax,esp  
0025187B  mov         dword ptr [eax],offset string "\xe4\xb8\xad\xe5\x8d\x8e\xe4\xba\xba\xe6\xb0\x91\xe5\x85\xb1\xe5\x92\x8c\xe5\x9b\xbd\xe5\x88\x91\xe6\xb3\x95" (025B0CBh)  
00251881  lea         ecx,[esi+14Ch]  
00251887  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string (0252E90h)  
0025188C  sub         esp,4  
0025188F  jmp         main+894h (0251894h)  
00251894  mov         dword ptr [esi+5E8h],7  
0025189E  mov         eax,esp  
002518A0  lea         ecx,[esi+174h]  
002518A6  mov         dword ptr [eax+8],ecx  
002518A9  lea         ecx,[esi+168h]  
002518AF  mov         dword ptr [eax+4],ecx  
002518B2  lea         ecx,[esi+14Ch]  
002518B8  mov         dword ptr [eax],ecx  
002518BA  lea         ecx,[esi+178h]  
002518C0  call        Book::Book (02520E0h)  
002518C5  sub         esp,0Ch  
002518C8  jmp         main+8CDh (02518CDh)  
002518CD  mov         dword ptr [esi+5E8h],8  
002518D7  mov         eax,esp  
002518D9  lea         ecx,[esi+178h]  
002518DF  mov         dword ptr [eax],ecx  
002518E1  lea         ecx,[library]  
002518E7  call        std::vector<Book,std::allocator<Book> >::emplace_back<Book> (0252E10h)  
002518EC  sub         esp,4  
002518EF  jmp         main+8F4h (02518F4h)  
002518F4  lea         ecx,[esi+178h]  
002518FA  call        Book::~Book (0252FC0h)  
002518FF  lea         ecx,[esi+14Ch]  
00251905  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
	library.emplace_back(Book("茶馆", 49, 278));
0025190A  mov         dword ptr [esi+114h],116h  
00251914  mov         dword ptr [esi+10Ch],40488000h  
0025191E  mov         dword ptr [esi+108h],0  
00251928  mov         dword ptr [esi+5E8h],0  
00251932  mov         eax,esp  
00251934  mov         dword ptr [eax],offset string "\xe8\x8c\xb6\xe9\xa6\x86" (025B0E7h)  
0025193A  lea         ecx,[esi+0ECh]  
00251940  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string (0252E90h)  
00251945  sub         esp,4  
00251948  jmp         main+94Dh (025194Dh)  
0025194D  mov         dword ptr [esi+5E8h],5  
00251957  mov         eax,esp  
00251959  lea         ecx,[esi+114h]  
0025195F  mov         dword ptr [eax+8],ecx  
00251962  lea         ecx,[esi+108h]  
00251968  mov         dword ptr [eax+4],ecx  
0025196B  lea         ecx,[esi+0ECh]  
00251971  mov         dword ptr [eax],ecx  
00251973  lea         ecx,[esi+118h]  
00251979  call        Book::Book (02520E0h)  
0025197E  sub         esp,0Ch  
00251981  jmp         main+986h (0251986h)  
00251986  mov         dword ptr [esi+5E8h],6  
00251990  mov         eax,esp  
00251992  lea         ecx,[esi+118h]  
00251998  mov         dword ptr [eax],ecx  
0025199A  lea         ecx,[library]  
002519A0  call        std::vector<Book,std::allocator<Book> >::emplace_back<Book> (0252E10h)  
002519A5  sub         esp,4  
002519A8  jmp         main+9ADh (02519ADh)  
002519AD  lea         ecx,[esi+118h]  
002519B3  call        Book::~Book (0252FC0h)  
002519B8  lea         ecx,[esi+0ECh]  
002519BE  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
	library.emplace_back(Book("边城", 32, 72));
002519C3  mov         dword ptr [esi+0B4h],48h  
002519CD  mov         dword ptr [esi+0ACh],40400000h  
002519D7  mov         dword ptr [esi+0A8h],0  
002519E1  mov         dword ptr [esi+5E8h],0  
002519EB  mov         eax,esp  
002519ED  mov         dword ptr [eax],offset string "\xe8\xbe\xb9\xe5\x9f\x8e" (025B0EEh)  
002519F3  lea         ecx,[esi+8Ch]  
002519F9  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string (0252E90h)  
002519FE  sub         esp,4  
00251A01  jmp         main+0A06h (0251A06h)  
00251A06  mov         dword ptr [esi+5E8h],3  
00251A10  mov         eax,esp  
00251A12  lea         ecx,[esi+0B4h]  
00251A18  mov         dword ptr [eax+8],ecx  
00251A1B  lea         ecx,[esi+0A8h]  
00251A21  mov         dword ptr [eax+4],ecx  
00251A24  lea         ecx,[esi+8Ch]  
00251A2A  mov         dword ptr [eax],ecx  
00251A2C  lea         ecx,[esi+0B8h]  
00251A32  call        Book::Book (02520E0h)  
00251A37  sub         esp,0Ch  
00251A3A  jmp         main+0A3Fh (0251A3Fh)  
00251A3F  mov         dword ptr [esi+5E8h],4  
00251A49  mov         eax,esp  
00251A4B  lea         ecx,[esi+0B8h]  
00251A51  mov         dword ptr [eax],ecx  
00251A53  lea         ecx,[library]  
00251A59  call        std::vector<Book,std::allocator<Book> >::emplace_back<Book> (0252E10h)  
00251A5E  sub         esp,4  
00251A61  jmp         main+0A66h (0251A66h)  
00251A66  lea         ecx,[esi+0B8h]  
00251A6C  call        Book::~Book (0252FC0h)  
00251A71  lea         ecx,[esi+8Ch]  
00251A77  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
	library.emplace_back(Book("活着", 38, 682));
00251A7C  mov         dword ptr [esi+54h],2AAh  
00251A83  mov         dword ptr [esi+4Ch],40430000h  
00251A8A  mov         dword ptr [esi+48h],0  
00251A91  mov         dword ptr [esi+5E8h],0  
00251A9B  mov         eax,esp  
00251A9D  mov         dword ptr [eax],offset string "\xe6\xb4\xbb\xe7\x9d\x80" (025B0F5h)  
00251AA3  lea         ecx,[esi+2Ch]  
00251AA6  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string (0252E90h)  
00251AAB  sub         esp,4  
00251AAE  jmp         main+0AB3h (0251AB3h)  
00251AB3  mov         dword ptr [esi+5E8h],1  
00251ABD  mov         eax,esp  
00251ABF  lea         ecx,[esi+54h]  
00251AC2  mov         dword ptr [eax+8],ecx  
00251AC5  lea         ecx,[esi+48h]  
00251AC8  mov         dword ptr [eax+4],ecx  
00251ACB  lea         ecx,[esi+2Ch]  
00251ACE  mov         dword ptr [eax],ecx  
00251AD0  lea         ecx,[esi+58h]  
00251AD3  call        Book::Book (02520E0h)  
00251AD8  sub         esp,0Ch  
00251ADB  jmp         main+0AE0h (0251AE0h)  
00251AE0  mov         dword ptr [esi+5E8h],2  
00251AEA  mov         eax,esp  
00251AEC  lea         ecx,[esi+58h]  
00251AEF  mov         dword ptr [eax],ecx  
00251AF1  lea         ecx,[library]  
00251AF7  call        std::vector<Book,std::allocator<Book> >::emplace_back<Book> (0252E10h)  
00251AFC  sub         esp,4  
00251AFF  jmp         main+0B04h (0251B04h)  
00251B04  lea         ecx,[esi+58h]  
00251B07  call        Book::~Book (0252FC0h)  
00251B0C  lea         ecx,[esi+2Ch]  
00251B0F  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
		cout <<
00251B14  mov         dword ptr [esi+5E8h],0  
00251B1E  mov         ecx,dword ptr [__imp_std::cout (025C244h)]  
00251B24  mov         eax,esp  
00251B26  mov         dword ptr [eax],ecx  
00251B28  mov         dword ptr [eax+4],offset string "***********************        \xe6"... (025B0FCh)  
00251B2F  call        std::operator<<<std::char_traits<char> > (0253060h)  
00251B34  mov         dword ptr [esi+24h],eax  
00251B37  jmp         main+0B3Ch (0251B3Ch)  
00251B3C  mov         ecx,dword ptr [esi+24h]  
00251B3F  mov         eax,esp  
00251B41  mov         dword ptr [eax],ecx  
00251B43  mov         dword ptr [eax+4],offset string "\xe6\x93\x8d\xe4\xbd\x9c\xe8\xaf\xb4\xe6\x98\x8e\xef\xbc\x9a0-\xe9\x80\x80\xe5\x87\xba\xe7\xb3\xbb\xe7\xbb\x9f\xef\xbc\x9b"... (025B157h)  
00251B4A  call        std::operator<<<std::char_traits<char> > (0253060h)  
00251B4F  mov         dword ptr [esi+20h],eax  
00251B52  jmp         main+0B57h (0251B57h)  
00251B57  mov         ecx,dword ptr [esi+20h]  
00251B5A  mov         eax,esp  
00251B5C  mov         dword ptr [eax],ecx  
00251B5E  mov         dword ptr [eax+4],offset string "\xe8\xaf\xb7\xe8\xbe\x93\xe5\x85\xa5\xe6\x93\x8d\xe4\xbd\x9c\xef\xbc\x9a" (025B1CBh)  
00251B65  call        std::operator<<<std::char_traits<char> > (0253060h)  
00251B6A  jmp         main+0B6Fh (0251B6Fh)  
			"***********************        欢迎进入图书馆系统        ***********************\n" <<
			"操作说明：0-退出系统；1-显示库存；2-查询图书；3-借阅图书；4-归还图书；5-增加图书\n" <<
			"请输入操作：";

		if (!(cin >> choice)) {
00251B6F  mov         eax,esp  
00251B71  lea         ecx,[choice]  
00251B74  mov         dword ptr [eax],ecx  
00251B76  mov         ecx,dword ptr [__imp_std::cin (025C23Ch)]  
00251B7C  mov         eax,dword ptr [__imp_std::basic_istream<char,std::char_traits<char> >::operator>> (025C1F8h)]  
00251B81  call        eax  
00251B83  sub         esp,4  
00251B86  mov         dword ptr [esi+1Ch],eax  
00251B89  jmp         main+0B8Eh (0251B8Eh)  
00251B8E  mov         ecx,dword ptr [esi+1Ch]  
00251B91  mov         eax,dword ptr [ecx]  
00251B93  mov         eax,dword ptr [eax+4]  
00251B96  add         ecx,eax  
00251B98  mov         eax,dword ptr [__imp_std::ios_base::operator! (025C20Ch)]  
00251B9D  call        eax  
00251B9F  mov         byte ptr [esi+1Bh],al  
00251BA2  jmp         main+0BA7h (0251BA7h)  
00251BA7  mov         al,byte ptr [esi+1Bh]  
00251BAA  test        al,1  
00251BAC  jne         main+0BB7h (0251BB7h)  
00251BB2  jmp         main+0BF4h (0251BF4h)  
			cout << "输入非法，请重试" << endl;
00251BB7  mov         ecx,dword ptr [__imp_std::cout (025C244h)]  
00251BBD  mov         eax,esp  
00251BBF  mov         dword ptr [eax],ecx  
00251BC1  mov         dword ptr [eax+4],offset string "\xe8\xbe\x93\xe5\x85\xa5\xe9\x9d\x9e\xe6\xb3\x95\xef\xbc\x8c\xe8\xaf\xb7\xe9\x87\x8d\xe8\xaf\x95" (025B1DEh)  
00251BC8  call        std::operator<<<std::char_traits<char> > (0253060h)  
00251BCD  mov         dword ptr [esi+14h],eax  
00251BD0  jmp         main+0BD5h (0251BD5h)  
00251BD5  mov         ecx,dword ptr [esi+14h]  
00251BD8  mov         eax,esp  
00251BDA  mov         dword ptr [eax],offset std::endl<char,std::char_traits<char> > (02534D0h)  
00251BE0  mov         eax,dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (025C208h)]  
00251BE5  call        eax  
00251BE7  sub         esp,4  
00251BEA  jmp         main+0BEFh (0251BEFh)  
		}
00251BEF  jmp         main+0BF4h (0251BF4h)  

		switch (choice) {
00251BF4  mov         eax,dword ptr [choice]  
00251BF7  mov         dword ptr [esi+10h],eax  
00251BFA  sub         eax,5  
00251BFD  ja          main+0CDCh (0251CDCh)  
00251C03  mov         eax,dword ptr [esi+10h]  
00251C06  mov         eax,dword ptr [eax*4+25B000h]  
00251C0D  jmp         eax  
		case 0:
			exit(0);
00251C0F  xor         eax,eax  
00251C11  mov         dword ptr [esp],0  
00251C18  call        dword ptr [__imp__exit (025C398h)]  
		case 1:
			printf_s("********************************************************************************\n");
00251C1E  mov         eax,esp  
00251C20  mov         dword ptr [eax],offset string "********************************"... (025B1F7h)  
00251C26  call        printf_s (0253520h)  
			display_stock(library);
00251C2B  mov         eax,esp  
00251C2D  lea         ecx,[library]  
00251C33  mov         dword ptr [eax],ecx  
00251C35  call        display_stock (02521A0h)  
00251C3A  jmp         main+0C3Fh (0251C3Fh)  
			break;
00251C3F  jmp         main+0CF8h (0251CF8h)  
		case 2:
			printf_s("********************************************************************************\n");
00251C44  mov         eax,esp  
00251C46  mov         dword ptr [eax],offset string "********************************"... (025B1F7h)  
00251C4C  call        printf_s (0253520h)  
			search_book(library);
00251C51  mov         eax,esp  
00251C53  lea         ecx,[library]  
00251C59  mov         dword ptr [eax],ecx  
00251C5B  call        search_book (02522A0h)  
00251C60  jmp         main+0C65h (0251C65h)  
			break;
00251C65  jmp         main+0CF8h (0251CF8h)  
		case 3:
			printf_s("********************************************************************************\n");
00251C6A  mov         eax,esp  
00251C6C  mov         dword ptr [eax],offset string "********************************"... (025B1F7h)  
00251C72  call        printf_s (0253520h)  
			borrow_book(library);
00251C77  mov         eax,esp  
00251C79  lea         ecx,[library]  
00251C7F  mov         dword ptr [eax],ecx  
00251C81  call        borrow_book (0252460h)  
00251C86  jmp         main+0C8Bh (0251C8Bh)  
			break;
00251C8B  jmp         main+0CF8h (0251CF8h)  
		case 4:
			printf_s("********************************************************************************\n");
00251C90  mov         eax,esp  
00251C92  mov         dword ptr [eax],offset string "********************************"... (025B1F7h)  
00251C98  call        printf_s (0253520h)  
			give_back_book(library);
00251C9D  mov         eax,esp  
00251C9F  lea         ecx,[library]  
00251CA5  mov         dword ptr [eax],ecx  
00251CA7  call        give_back_book (02525F0h)  
00251CAC  jmp         main+0CB1h (0251CB1h)  
			break;
00251CB1  jmp         main+0CF8h (0251CF8h)  
		case 5:
			printf_s("********************************************************************************\n");
00251CB6  mov         eax,esp  
00251CB8  mov         dword ptr [eax],offset string "********************************"... (025B1F7h)  
00251CBE  call        printf_s (0253520h)  
			add_book(library);
00251CC3  mov         eax,esp  
00251CC5  lea         ecx,[library]  
00251CCB  mov         dword ptr [eax],ecx  
00251CCD  call        add_book (0252780h)  
00251CD2  jmp         main+0CD7h (0251CD7h)  
			break;
00251CD7  jmp         main+0CF8h (0251CF8h)  
		default:
			printf_s("********************************************************************************\n");
00251CDC  lea         eax,[string "********************************"... (025B1F7h)]  
00251CE2  mov         dword ptr [esp],eax  
00251CE5  call        printf_s (0253520h)  
			printf_s("无效操作，请重试。\n");
00251CEA  lea         eax,[string "\xe6\x97\xa0\xe6\x95\x88\xe6\x93\x8d\xe4\xbd\x9c\xef\xbc\x8c\xe8\xaf\xb7\xe9\x87\x8d\xe8\xaf\x95\xe3\x80\x82\n" (025B249h)]  
00251CF0  mov         dword ptr [esp],eax  
00251CF3  call        printf_s (0253520h)  

	int choice;
	while (true) {
00251CF8  jmp         main+0B14h (0251B14h)  
00251CFD  nop         dword ptr [eax]  
00251D00  push        ebp  
00251D01  sub         esp,0Ch  
00251D04  lea         esi,[ebp-5ECh]  
00251D0A  mov         ebp,dword ptr [esi+0Ch]  
00251D0D  lea         ecx,[esi+598h]  
	library.emplace_back(Book("数学之美", 35, 275));
00251D13  call        Book::~Book (0252FC0h)  
00251D18  add         esp,0Ch  
00251D1B  pop         ebp  
00251D1C  ret  
00251D1D  nop         dword ptr [eax]  
00251D20  push        ebp  
00251D21  sub         esp,0Ch  
00251D24  lea         esi,[ebp-5ECh]  
00251D2A  mov         ebp,dword ptr [esi+0Ch]  
00251D2D  lea         ecx,[esi+56Ch]  
00251D33  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
00251D38  add         esp,0Ch  
00251D3B  pop         ebp  
00251D3C  ret  
00251D3D  nop         dword ptr [eax]  
00251D40  push        ebp  
00251D41  sub         esp,0Ch  
00251D44  lea         esi,[ebp-5ECh]  
00251D4A  mov         ebp,dword ptr [esi+0Ch]  
00251D4D  lea         ecx,[esi+538h]  
	library.emplace_back(Book("浪潮之巅", 39, 287));
00251D53  call        Book::~Book (0252FC0h)  
00251D58  add         esp,0Ch  
00251D5B  pop         ebp  
00251D5C  ret  
00251D5D  nop         dword ptr [eax]  
00251D60  push        ebp  
00251D61  sub         esp,0Ch  
00251D64  lea         esi,[ebp-5ECh]  
00251D6A  mov         ebp,dword ptr [esi+0Ch]  
00251D6D  lea         ecx,[esi+50Ch]  
00251D73  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
00251D78  add         esp,0Ch  
00251D7B  pop         ebp  
00251D7C  ret  
00251D7D  nop         dword ptr [eax]  
00251D80  push        ebp  
00251D81  sub         esp,0Ch  
00251D84  lea         esi,[ebp-5ECh]  
00251D8A  mov         ebp,dword ptr [esi+0Ch]  
00251D8D  lea         ecx,[esi+4D8h]  
	library.emplace_back(Book("计算之魂", 55, 27));
00251D93  call        Book::~Book (0252FC0h)  
00251D98  add         esp,0Ch  
00251D9B  pop         ebp  
00251D9C  ret  
00251D9D  nop         dword ptr [eax]  
00251DA0  push        ebp  
00251DA1  sub         esp,0Ch  
00251DA4  lea         esi,[ebp-5ECh]  
00251DAA  mov         ebp,dword ptr [esi+0Ch]  
00251DAD  lea         ecx,[esi+4ACh]  
00251DB3  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
00251DB8  add         esp,0Ch  
00251DBB  pop         ebp  
00251DBC  ret  
00251DBD  nop         dword ptr [eax]  
00251DC0  push        ebp  
00251DC1  sub         esp,0Ch  
00251DC4  lea         esi,[ebp-5ECh]  
00251DCA  mov         ebp,dword ptr [esi+0Ch]  
00251DCD  lea         ecx,[esi+478h]  
	library.emplace_back(Book("三国演义", 20, 685));
00251DD3  call        Book::~Book (0252FC0h)  
00251DD8  add         esp,0Ch  
00251DDB  pop         ebp  
00251DDC  ret  
00251DDD  nop         dword ptr [eax]  
00251DE0  push        ebp  
00251DE1  sub         esp,0Ch  
00251DE4  lea         esi,[ebp-5ECh]  
00251DEA  mov         ebp,dword ptr [esi+0Ch]  
00251DED  lea         ecx,[esi+44Ch]  
00251DF3  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
00251DF8  add         esp,0Ch  
00251DFB  pop         ebp  
00251DFC  ret  
00251DFD  nop         dword ptr [eax]  
00251E00  push        ebp  
00251E01  sub         esp,0Ch  
00251E04  lea         esi,[ebp-5ECh]  
00251E0A  mov         ebp,dword ptr [esi+0Ch]  
00251E0D  lea         ecx,[esi+418h]  
	library.emplace_back(Book("五年单身，三年当狗", 10, 185));
00251E13  call        Book::~Book (0252FC0h)  
00251E18  add         esp,0Ch  
00251E1B  pop         ebp  
00251E1C  ret  
00251E1D  nop         dword ptr [eax]  
00251E20  push        ebp  
00251E21  sub         esp,0Ch  
00251E24  lea         esi,[ebp-5ECh]  
00251E2A  mov         ebp,dword ptr [esi+0Ch]  
00251E2D  lea         ecx,[esi+3ECh]  
00251E33  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
00251E38  add         esp,0Ch  
00251E3B  pop         ebp  
00251E3C  ret  
00251E3D  nop         dword ptr [eax]  
00251E40  push        ebp  
00251E41  sub         esp,0Ch  
00251E44  lea         esi,[ebp-5ECh]  
00251E4A  mov         ebp,dword ptr [esi+0Ch]  
00251E4D  lea         ecx,[esi+3B8h]  
	library.emplace_back(Book("中国共产党简史", 20, 927));
00251E53  call        Book::~Book (0252FC0h)  
00251E58  add         esp,0Ch  
00251E5B  pop         ebp  
00251E5C  ret  
00251E5D  nop         dword ptr [eax]  
00251E60  push        ebp  
00251E61  sub         esp,0Ch  
00251E64  lea         esi,[ebp-5ECh]  
00251E6A  mov         ebp,dword ptr [esi+0Ch]  
00251E6D  lea         ecx,[esi+38Ch]  
00251E73  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
00251E78  add         esp,0Ch  
00251E7B  pop         ebp  
00251E7C  ret  
00251E7D  nop         dword ptr [eax]  
00251E80  push        ebp  
00251E81  sub         esp,0Ch  
00251E84  lea         esi,[ebp-5ECh]  
00251E8A  mov         ebp,dword ptr [esi+0Ch]  
00251E8D  lea         ecx,[esi+358h]  
	library.emplace_back(Book("文明之光", 30, 278));
00251E93  call        Book::~Book (0252FC0h)  
00251E98  add         esp,0Ch  
00251E9B  pop         ebp  
00251E9C  ret  
00251E9D  nop         dword ptr [eax]  
00251EA0  push        ebp  
00251EA1  sub         esp,0Ch  
00251EA4  lea         esi,[ebp-5ECh]  
00251EAA  mov         ebp,dword ptr [esi+0Ch]  
00251EAD  lea         ecx,[esi+32Ch]  
00251EB3  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
00251EB8  add         esp,0Ch  
00251EBB  pop         ebp  
00251EBC  ret  
00251EBD  nop         dword ptr [eax]  
00251EC0  push        ebp  
00251EC1  sub         esp,0Ch  
00251EC4  lea         esi,[ebp-5ECh]  
00251ECA  mov         ebp,dword ptr [esi+0Ch]  
00251ECD  lea         ecx,[esi+2F8h]  
	library.emplace_back(Book("编译系统", 60, 627));
00251ED3  call        Book::~Book (0252FC0h)  
00251ED8  add         esp,0Ch  
00251EDB  pop         ebp  
00251EDC  ret  
00251EDD  nop         dword ptr [eax]  
00251EE0  push        ebp  
00251EE1  sub         esp,0Ch  
00251EE4  lea         esi,[ebp-5ECh]  
00251EEA  mov         ebp,dword ptr [esi+0Ch]  
00251EED  lea         ecx,[esi+2CCh]  
00251EF3  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
00251EF8  add         esp,0Ch  
00251EFB  pop         ebp  
00251EFC  ret  
00251EFD  nop         dword ptr [eax]  
00251F00  push        ebp  
00251F01  sub         esp,0Ch  
00251F04  lea         esi,[ebp-5ECh]  
00251F0A  mov         ebp,dword ptr [esi+0Ch]  
00251F0D  lea         ecx,[esi+298h]  
	library.emplace_back(Book("从一到无穷大", 40, 625));
00251F13  call        Book::~Book (0252FC0h)  
00251F18  add         esp,0Ch  
00251F1B  pop         ebp  
00251F1C  ret  
00251F1D  nop         dword ptr [eax]  
00251F20  push        ebp  
00251F21  sub         esp,0Ch  
00251F24  lea         esi,[ebp-5ECh]  
00251F2A  mov         ebp,dword ptr [esi+0Ch]  
00251F2D  lea         ecx,[esi+26Ch]  
00251F33  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
00251F38  add         esp,0Ch  
00251F3B  pop         ebp  
00251F3C  ret  
00251F3D  nop         dword ptr [eax]  
00251F40  push        ebp  
00251F41  sub         esp,0Ch  
00251F44  lea         esi,[ebp-5ECh]  
00251F4A  mov         ebp,dword ptr [esi+0Ch]  
00251F4D  lea         ecx,[esi+238h]  
	library.emplace_back(Book("影响力", 40, 157));
00251F53  call        Book::~Book (0252FC0h)  
00251F58  add         esp,0Ch  
00251F5B  pop         ebp  
00251F5C  ret  
00251F5D  nop         dword ptr [eax]  
00251F60  push        ebp  
00251F61  sub         esp,0Ch  
00251F64  lea         esi,[ebp-5ECh]  
00251F6A  mov         ebp,dword ptr [esi+0Ch]  
00251F6D  lea         ecx,[esi+20Ch]  
00251F73  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
00251F78  add         esp,0Ch  
00251F7B  pop         ebp  
00251F7C  ret  
00251F7D  nop         dword ptr [eax]  
00251F80  push        ebp  
00251F81  sub         esp,0Ch  
00251F84  lea         esi,[ebp-5ECh]  
00251F8A  mov         ebp,dword ptr [esi+0Ch]  
00251F8D  lea         ecx,[esi+1D8h]  
	library.emplace_back(Book("C++从入门到放弃", 9.9, 278));
00251F93  call        Book::~Book (0252FC0h)  
00251F98  add         esp,0Ch  
00251F9B  pop         ebp  
00251F9C  ret  
00251F9D  nop         dword ptr [eax]  
00251FA0  push        ebp  
00251FA1  sub         esp,0Ch  
00251FA4  lea         esi,[ebp-5ECh]  
00251FAA  mov         ebp,dword ptr [esi+0Ch]  
00251FAD  lea         ecx,[esi+1ACh]  
00251FB3  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
00251FB8  add         esp,0Ch  
00251FBB  pop         ebp  
00251FBC  ret  
00251FBD  nop         dword ptr [eax]  
00251FC0  push        ebp  
00251FC1  sub         esp,0Ch  
00251FC4  lea         esi,[ebp-5ECh]  
00251FCA  mov         ebp,dword ptr [esi+0Ch]  
00251FCD  lea         ecx,[esi+178h]  
	library.emplace_back(Book("中华人民共和国刑法", 56, 378));
00251FD3  call        Book::~Book (0252FC0h)  
00251FD8  add         esp,0Ch  
00251FDB  pop         ebp  
00251FDC  ret  
00251FDD  nop         dword ptr [eax]  
00251FE0  push        ebp  
00251FE1  sub         esp,0Ch  
00251FE4  lea         esi,[ebp-5ECh]  
00251FEA  mov         ebp,dword ptr [esi+0Ch]  
00251FED  lea         ecx,[esi+14Ch]  
00251FF3  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
00251FF8  add         esp,0Ch  
00251FFB  pop         ebp  
00251FFC  ret  
00251FFD  nop         dword ptr [eax]  
00252000  push        ebp  
00252001  sub         esp,0Ch  
00252004  lea         esi,[ebp-5ECh]  
0025200A  mov         ebp,dword ptr [esi+0Ch]  
0025200D  lea         ecx,[esi+118h]  
	library.emplace_back(Book("茶馆", 49, 278));
00252013  call        Book::~Book (0252FC0h)  
00252018  add         esp,0Ch  
0025201B  pop         ebp  
0025201C  ret  
0025201D  nop         dword ptr [eax]  
00252020  push        ebp  
00252021  sub         esp,0Ch  
00252024  lea         esi,[ebp-5ECh]  
0025202A  mov         ebp,dword ptr [esi+0Ch]  
0025202D  lea         ecx,[esi+0ECh]  
00252033  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
00252038  add         esp,0Ch  
0025203B  pop         ebp  
0025203C  ret  
0025203D  nop         dword ptr [eax]  
00252040  push        ebp  
00252041  sub         esp,0Ch  
00252044  lea         esi,[ebp-5ECh]  
0025204A  mov         ebp,dword ptr [esi+0Ch]  
0025204D  lea         ecx,[esi+0B8h]  
	library.emplace_back(Book("边城", 32, 72));
00252053  call        Book::~Book (0252FC0h)  
00252058  add         esp,0Ch  
0025205B  pop         ebp  
0025205C  ret  
0025205D  nop         dword ptr [eax]  
00252060  push        ebp  
00252061  sub         esp,0Ch  
00252064  lea         esi,[ebp-5ECh]  
0025206A  mov         ebp,dword ptr [esi+0Ch]  
0025206D  lea         ecx,[esi+8Ch]  
00252073  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
00252078  add         esp,0Ch  
0025207B  pop         ebp  
0025207C  ret  
0025207D  nop         dword ptr [eax]  
00252080  push        ebp  
00252081  sub         esp,0Ch  
00252084  lea         esi,[ebp-5ECh]  
0025208A  mov         ebp,dword ptr [esi+0Ch]  
0025208D  lea         ecx,[esi+58h]  
	library.emplace_back(Book("活着", 38, 682));
00252090  call        Book::~Book (0252FC0h)  
00252095  add         esp,0Ch  
00252098  pop         ebp  
00252099  ret  
0025209A  nop         word ptr [eax+eax]  
002520A0  push        ebp  
002520A1  sub         esp,0Ch  
002520A4  lea         esi,[ebp-5ECh]  
002520AA  mov         ebp,dword ptr [esi+0Ch]  
002520AD  lea         ecx,[esi+2Ch]  
002520B0  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
002520B5  add         esp,0Ch  
002520B8  pop         ebp  
002520B9  ret  
002520BA  nop         word ptr [eax+eax]  
002520C0  push        ebp  
002520C1  sub         esp,0Ch  
002520C4  lea         esi,[ebp-5ECh]  
002520CA  mov         ebp,dword ptr [esi+0Ch]  
002520CD  lea         ecx,[library]  
		}
	}
}
002520D3  call        std::vector<Book,std::allocator<Book> >::~vector (0253590h)  
002520D8  add         esp,0Ch  
002520DB  pop         ebp  
002520DC  ret  
--- 无源文件 -----------------------------------------------------------------------
002520DD  nop         dword ptr [eax]  
--- C:\Users\professor\Desktop\上课\计算机课\tmp5\tmp5.cpp ---------------------------

Book::Book(const string& bookname, const double& price, const int& number) {
002520E0  push        ebp  
002520E1  mov         ebp,esp  
002520E3  push        ebx  
002520E4  push        edi  
002520E5  push        esi  
002520E6  sub         esp,20h  
002520E9  mov         eax,dword ptr [ebp+10h]  
002520EC  mov         eax,dword ptr [ebp+0Ch]  
002520EF  mov         eax,dword ptr [ebp+8]  
002520F2  mov         eax,esp  
002520F4  mov         dword ptr [ebp-1Ch],eax  
002520F7  mov         dword ptr [ebp-10h],0FFFFFFFFh  
002520FE  lea         eax,[ebp-18h]  
00252101  mov         dword ptr [ebp-14h],252CA0h  
00252108  mov         edx,dword ptr fs:[0]  
0025210F  mov         dword ptr [ebp-18h],edx  
00252112  mov         dword ptr fs:[00000000h],eax  
00252118  mov         dword ptr [ebp-20h],ecx  
0025211B  mov         ecx,dword ptr [ebp-20h]  
0025211E  mov         dword ptr [ebp-24h],ecx  
00252121  mov         eax,ecx  
00252123  mov         dword ptr [ebp-28h],eax  
00252126  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::basic_string (02538C0h)  
0025212B  mov         ecx,dword ptr [ebp-24h]  
	this->bookname = bookname;
0025212E  mov         edx,dword ptr [bookname]  
00252131  mov         dword ptr [ebp-10h],0  
00252138  mov         eax,esp  
0025213A  mov         dword ptr [eax],edx  
0025213C  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::operator= (0253D30h)  
00252141  sub         esp,4  
00252144  jmp         Book::Book+69h (0252149h)  
	this->price = price;
00252149  mov         eax,dword ptr [ebp-28h]  
0025214C  mov         ecx,dword ptr [price]  
0025214F  movsd       xmm0,mmword ptr [ecx]  
00252153  movsd       mmword ptr [eax+20h],xmm0  
	this->number = number;
00252158  mov         ecx,dword ptr [number]  
0025215B  mov         ecx,dword ptr [ecx]  
0025215D  mov         dword ptr [eax+28h],ecx  
}
00252160  mov         ecx,dword ptr [ebp-18h]  
00252163  mov         dword ptr fs:[0],ecx  
0025216A  add         esp,20h  
0025216D  pop         esi  
0025216E  pop         edi  
0025216F  pop         ebx  
00252170  pop         ebp  
00252171  ret         0Ch  
00252174  nop         word ptr cs:[eax+eax]  
0025217E  nop  
00252180  push        ebp  
00252181  push        eax  
00252182  add         ebp,0Ch  
00252185  mov         ecx,dword ptr [ebp-24h]  
00252188  call        std::basic_string<char,std::char_traits<char>,std::allocator<char> >::~basic_string (0252FE0h)  
0025218D  add         esp,4  
00252190  pop         ebp  
00252191  ret  
--- 无源文件 -----------------------------------------------------------------------
00252192  nop         word ptr cs:[eax+eax]  
0025219C  nop         dword ptr [eax]  
--- C:\Users\professor\Desktop\上课\计算机课\tmp5\tmp5.cpp ---------------------------

void display_stock(const vector<Book>& library) {
002521A0  push        ebp  
002521A1  mov         ebp,esp  
002521A3  push        ebx  
002521A4  push        edi  
002521A5  push        esi  
002521A6  sub         esp,40h  
002521A9  mov         eax,dword ptr [ebp+8]  
002521AC  mov         eax,esp  
002521AE  mov         dword ptr [ebp-1Ch],eax  
002521B1  mov         dword ptr [ebp-10h],0FFFFFFFFh  
002521B8  lea         eax,[ebp-18h]  
002521BB  mov         dword ptr [ebp-14h],252CC0h  
002521C2  mov         ecx,dword ptr fs:[0]  
002521C9  mov         dword ptr [ebp-18h],ecx  
002521CC  mov         dword ptr fs:[00000000h],eax  
	for (vector<Book>::const_iterator it = library.cbegin(); it != library.cend(); it++) {
002521D2  mov         ecx,dword ptr [library]  
002521D5  lea         eax,[it]  
002521D8  mov         dword ptr [esp],eax  
002521DB  call        std::vector<Book,std::allocator<Book> >::cbegin (0253610h)  
002521E0  sub         esp,4  
002521E3  mov         ecx,dword ptr [library]  
002521E6  lea         eax,[ebp-34h]  
002521E9  mov         dword ptr [esp],eax  
002521EC  call        std::vector<Book,std::allocator<Book> >::cend (0253670h)  
002521F1  sub         esp,4  
002521F4  lea         ecx,[it]  
002521F7  lea         eax,[ebp-34h]  
002521FA  mov         dword ptr [esp],eax  
002521FD  call        std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<Book> > >::operator!= (0253640h)  
00252202  sub         esp,4  
00252205  mov         byte ptr [ebp-41h],al  
00252208  lea         ecx,[ebp-34h]  
0025220B  call        std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<Book> > >::~_Vector_const_iterator (02536A0h)  
00252210  mov         al,byte ptr [ebp-41h]  
00252213  test        al,1  
00252215  jne         display_stock+94h (0252234h)  
0025221B  lea         ecx,[it]  
0025221E  call        std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<Book> > >::~_Vector_const_iterator (02536A0h)  
	}
}
00252223  mov         eax,dword ptr [ebp-18h]  
00252226  mov         dword ptr fs:[00000000h],eax  
0025222C  add         esp,40h  
0025222F  pop         esi  
00252230  pop         edi  
00252231  pop         ebx  
00252232  pop         ebp  
00252233  ret  
		it->display();
00252234  lea         ecx,[ebp-28h]  
00252237  call        std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<Book> > >::operator-> (02536C0h)  
0025223C  mov         ecx,eax  
0025223E  mov         dword ptr [ebp-10h],0  
00252245  call        Book::display (0252AB0h)  
0025224A  jmp         display_stock+0AFh (025224Fh)  
	for (vector<Book>::const_iterator it = library.cbegin(); it != library.cend(); it++) {
0025224F  lea         ecx,[it]  
00252252  lea         eax,[ebp-40h]  
00252255  xor         edx,edx  
00252257  mov         dword ptr [esp],eax  
0025225A  mov         dword ptr [esp+4],0  
00252262  call        std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<Book> > >::operator++ (0253860h)  
00252267  sub         esp,8  
0025226A  lea         ecx,[ebp-40h]  
0025226D  call        std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<Book> > >::~_Vector_const_iterator (02536A0h)  
00252272  jmp         display_stock+43h (02521E3h)  
00252277  nop         word ptr [eax+eax]  
00252280  push        ebp  
00252281  sub         esp,8  
00252284  add         ebp,0Ch  
00252287  lea         ecx,[it]  
0025228A  call        std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<Book> > >::~_Vector_const_iterator (02536A0h)  
0025228F  add         esp,8  
00252292  pop         ebp  
00252293  ret  