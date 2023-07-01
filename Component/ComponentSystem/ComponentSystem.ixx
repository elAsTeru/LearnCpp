// (C) 2023.7.1 elAsTeru. //

export module ComponentSystem;
export import :Component;
export import :Owner;

// コンポーネントを付与できるオブジェクトを指定できる
// コンポーネントシステムを提供。

// GameObject用とDX12用にコンポーネントを作ったとする。
// GameObject用に作ったコンポーネントはDX12には使えない。
// DX12用に作ったコンポーネントはGameObjectには使えない。