## C++学習の記録
C++の基礎の復習や知らなかった機能を学習、ゲーム開発に使うプログラムの作成などに使用。

<details>
<summary>目次</summary>
 
- [開発環境と設定](#開発環境と設定)
  - [開発環境](#開発環境)
  - [プロジェクトの設定](#プロジェクトの設定)
  
</details>

## 開発環境と設定

### 開発環境
- Visual Studio 2022 v143ビルドツール
- C++ 20 
- Windows 10

### プロジェクトの設定
- [ソリューションエクスプローラー] -> [すべてのファイルを表示]

すべての構成 (プロパティページの上の構成項目)
- [全般] -> [出力ディレクトリ] -> 
```
$(SolutionDir)\BuildData\
```
- [全般] -> [中間ディレクトリ] -> 
```
$(SolutionDir)\BuildData\$(ProjectName)\$(Platform)\$(Configuration)\
```

Debug (プロパティページの上の構成項目)
- [C/C++] -> [コード生成] -> [ランタイムライブラリ] -> [マルチスレッド デバッグ (/MTd)]

Release (プロパティページの上の構成項目)
- [C/C++] -> [コード生成] -> [ランタイムライブラリ] -> [マルチスレッド (/MT)]
