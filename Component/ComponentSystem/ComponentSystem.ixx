// コンポーネントを付与できるオブジェクトを指定できる
// コンポーネントシステム。

// GameObject用とDX12用にコンポーネントを作ったとする。
// GameObject用に作ったコンポーネントはDX12には使えない。
// DX12用に作ったコンポーネントはGameObjectには使えない。

export module ComponentSystem;
export import :Component;
export import :Owner;