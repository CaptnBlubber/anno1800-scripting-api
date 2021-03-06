#pragma once


namespace NativeCallSetups
{

const char* ShipDispatch =
R"(
40 55                               // rex push rbp
53                                  // push   rbx
56                                  // push   rsi
57                                  // push   rdi
41 54                               // push   r12
41 55                               // push   r13
41 56                               // push   r14
41 57                               // push   r15
48 8d ac 24 a8 fd ff                // lea    rbp,[rsp-0x258]
ff                                  // 
48 81 ec 58 03 00 00                // sub    rsp,0x358
48 8b f1                            // mov    rsi,rcx
33 db                               // xor    ebx,ebx
4c 8b 01                            // mov    r8,QWORD PTR [rcx]
41 38 58 18                         // cmp    BYTE PTR [r8+0x18],bl
)";

const char* ShipDispatchPreCall =
R"(
[push volatile]
50
48 b8 [nativeCode : 8]              // movabs rax, nativeCode
ff d0                               // call   rax
90                                  // nop
58
[pop volatile]
c3                                  // ret
)";

const char* ShipTransfer =
R"(
48 8b c4                            // mov    rax,rsp
57                                  // push   rdi
41 54                               // push   r12
41 55                               // push   r13
41 56                               // push   r14
41 57                               // push   r15
48 83 ec 70                         // sub    rsp,0x70
48 c7 40 88 fe ff ff ff             // mov    QWORD PTR [rax-0x78],0xfffffffffffffffe
48 89 58 10                         // mov    QWORD PTR [rax+0x10],rbx
48 89 68 18                         // mov    QWORD PTR [rax+0x18],rbp
48 89 70 20                         // mov    QWORD PTR [rax+0x20],rsi
4c 8b f1                            // mov    r14,rcx
4c 8b 01                            // mov    r8,QWORD PTR [rcx]
41 b9 1c 00 00 00                   // mov    r9d,0x1c
41 80 78 18 00                      // cmp    BYTE PTR [r8+0x18],0x0
)";

const char* ShipTransferPreCall =
R"(
[push volatile]
50
48 b8 [nativeCode : 8]              // movabs rax, nativeCode
ff d0                               // call   rax
90                                  // nop
58
[pop volatile]
c3                                  // ret
)";

const char* ShipCargoDump =
R"(
48 89 5c 24 10                      // mov    QWORD PTR [rsp+0x10],rbx
44 88 4c 24 20                      // mov    BYTE PTR [rsp+0x20],r9b
48 89 4c 24 08                      // mov    QWORD PTR [rsp+0x8],rcx
55                                  // push   rbp
56                                  // push   rsi
57                                  // push   rdi
41 54                               // push   r12
41 55                               // push   r13
41 56                               // push   r14
41 57                               // push   r15
48 8d ac 24 b0 fe ff ff             // lea    rbp,[rsp-0x150]
48 81 ec 50 02 00 00                // sub    rsp,0x250
4d 8b f8                            // mov    r15,r8
8b fa                               // mov    edi,edx
)";

const char* ShipCargoDumpPreCall =
R"(
[push volatile]
48 83 ec 28                         // sub    rsp,0x28
48 b8 [nativeCode : 8]              // movabs rax, nativeCode
ff d0                               // call   rax
90                                  // nop
48 83 c4 28                         // add    rsp,0x28
[pop volatile]
c3                                  // ret
)";

const char* LoadCargoFromIslandToShip =
R"(
48 89 5c 24 18                      // mov    QWORD PTR [rsp+0x18],rbx
55                                  // push   rbp
56                                  // push   rsi
57                                  // push   rdi
41 54                               // push   r12
41 55                               // push   r13
41 56                               // push   r14
41 57                               // push   r15
48 83 ec 60                         // sub    rsp,0x60
4c 8b f1                            // mov    r14,rcx
4c 8b 01                            // mov    r8,QWORD PTR [rcx]
bf 1c 00 00 00                      // mov    edi,0x1c
41 80 78 18 00                      // cmp    BYTE PTR [r8+0x18],0x0
)";

const char* LoadCargoFromIslandToShipPreCall =
R"(
[push volatile]
50
48 83 ec 20                         // sub    rsp,0x20
48 b8 [nativeCode : 8]              // movabs rax, nativeCode
ff d0                               // call   rax
90                                  // nop
48 83 c4 20                         // add    rsp,0x20
58
[pop volatile]
c3                                  // ret
)";

const char* LoadCargoFromShipToIsland =
R"(
48 89 5c 24 18                      // mov    QWORD PTR [rsp+0x18],rbx
55                                  // push   rbp
56                                  // push   rsi
57                                  // push   rdi
41 54                               // push   r12
41 55                               // push   r13
41 56                               // push   r14
41 57                               // push   r15
48 83 ec 50                         // sub    rsp,0x50
4c 8b f1                            // mov    r14,rcx
4c 8b 01                            // mov    r8,QWORD PTR [rcx]
bf 1c 00 00 00                      // mov    edi,0x1c
41 80 78 18 00                      // cmp    BYTE PTR [r8+0x18],0x0
)";

const char* LoadCargoFromShipToIslandPreCall =
R"(
[push volatile]
50
48 83 ec 20                         // sub    rsp,0x20
48 b8 [nativeCode : 8]              // movabs rax, nativeCode
ff d0                               // call   rax
90                                  // nop
48 83 c4 20                         // add    rsp,0x20
58
[pop volatile]
c3                                  // ret
)";


const char* VirtualShipGetComponent =
R"(
48 83 ec 20             // sub    rsp,0x20
48 8b 01                // mov    rax,QWORD PTR [rcx]
ff 50 18                // call   QWORD PTR [rax+0x18]
90                      // nop
48 83 c4 20             // add    rsp,0x20
c3                      // ret
)";

const char* VirtualBuildingGetComponent =
R"(
48 83 ec 20             // sub    rsp,0x20
48 8b 01                // mov    rax,QWORD PTR [rcx]
ff 50 18                // call   QWORD PTR [rax+0x18]
90                      // nop
48 83 c4 20             // add    rsp,0x20
c3                      // ret
)";

}
