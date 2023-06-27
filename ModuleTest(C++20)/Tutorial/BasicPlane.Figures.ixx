// 『プライマリ モジュール インターフェース ユニット』
// the export module keywords mark this file as a primary module interface unit
export module BasicPlane.Figures;

// bring in the Point partition, and export it to consumers of this module
// 指定されたモジュールをインポートし、このモジュールのコンシューマーに表示するようにコンパイラに指示
export import :Point;
// bring int the Rectangle partition, and export it to consumers of this module
// 指定されたモジュールをインポートし、このモジュールのコンシューマーに表示するようにコンパイラに指示
export import :Rectangle;