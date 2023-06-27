// 『モジュールの実装 ファイル』
module;
// global module fragment area. Put #include firectives here
// グローバル モジュール フラグメント と呼ばれるモジュールの特別な領域を導入
// windows.hやunistd.h(Linuxの場合)などのヘッダーファイルをインクルードするのに適した場所

// ここで構成するモジュール実装ファイルでは、ライブラリをインクルードしない。
// 実装の一部として必要ないため。しかし、必要な場合はこの領域に#includeディレティブを置く。
// (何を言いたいのか：#includeするときはmodule;の下に書いてねってことです。)

module BasicPlane.Figures:Rectangle;

int area(const Rectangle& _r) { return width(_r) * height(_r); }
int height(const Rectangle& _r) { return _r.ul.y - _r.lr.y; }
int width(const Rectangle& _r) { return _r.lr.x - _r.ul.x; }