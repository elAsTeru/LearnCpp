## C++学習の記録

<details>
<summary>目次</summary>
 
- [開発環境と設定](#開発環境と設定)
  - [開発環境](#開発環境)
  - [Visual Studio 設定](#Visual-Studio-設定)
  
</details>

## 開発環境と設定

### 開発環境
- Visual Studio 2022 v143ビルドツール
- C++ 20 
- Windows 10

### Visual Studio 設定
- [ソリューションエクスプローラー] -> [すべてのファイルを表示]

すべての構成 (プロパティページの上の構成項目)
- [全般] -> [C++ 言語標準] -> [ISO C++20 標準(/std:c++20)]
- [全般] -> [出力ディレクトリ] -> 
```
$(SolutionDir)\BuildData\
```
- [全般] -> [中間ディレクトリ] -> 
```
$(SolutionDir)\BuildData\$(ProjectName)\$(Platform)\$(Configuration)\
```
- [C/C++] -> [言語] -> [試験段階のC++標準ライブラリモジュールを有効にする] -> [はい]

Debug (プロパティページの上の構成項目)
- [C/C++] -> [コード生成] -> [ランタイムライブラリ] -> [マルチスレッド デバッグ (/MTd)]

Release (プロパティページの上の構成項目)
- [C/C++] -> [コード生成] -> [ランタイムライブラリ] -> [マルチスレッド (/MT)]