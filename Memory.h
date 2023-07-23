#pragma once
#include <memory>
#include <vector>

template  <class T>
struct  LinearAllocator {
	std::vector<T> allocator;
	void allocate(T& newinstance)
	{
		
			allocator.push_back(newinstance);
		
	}

	void deallocate(T& instance)
	{
		
		for(auto i=0;i<allocator.size()i++){
			if (allocator[i] == instance)
				instance = nullptr;
			allocator.erase(allocator.begin()+i);
		}
		else
		{
			throw std::runtime_error("Instanceは存在しません");
		}



	}

};
struct MallocAllocator {
	std::allocator<int> allocator;
	void* allocate(int size);

	

	void deallocate(int* pointer,int size_to_remove);
};







	size_t memory_align(size_t size, int alignment)
	{
		const size_t alignmentmask = alignment - 1;
		
		return (size + alignmentmask) & ~alignmentmask;
	}
	/*
このコードは、与えられたサイズとアライメント（配置境界）に基づいて、メモリのアライメントを調整するための関数です。

関数 `memory_align` は、2つの引数 `size` と `alignment` を取ります。`size` はメモリのサイズを表し、`alignment` は配置境界を表します。

関数の動作は以下の通りです：

1. `alignment_mask` という変数を `alignment - 1` で初期化します。これは、与えられたアライメント値から1を引いた値であり、アライメントマスクとして使用されます。アライメントマスクは、指定されたアライメントに対応するビットパターンです。

2. `(size + alignment_mask)` を計算します。これは、指定されたサイズにアライメントマスクを加えることで、アライメントを満たすために必要な最小のメモリサイズを計算します。

3. `~alignment_mask` を計算します。これは、アライメントマスクのビットを反転させたものです。これにより、指定されたアライメントに従ってビットが設定されたメモリアドレスを取得できます。

4. `(size + alignment_mask) & ~alignment_mask` を計算して、最終的なアライメント済みのメモリサイズを返します。これは、計算されたサイズとアライメントマスクとのビット単位のビットAND演算です。ビットAND演算により、アライメントマスクで設定されたビット以外はすべてゼロになります。

この関数は、指定されたサイズとアライメントに基づいて、アライメントを満たすために必要なメモリのサイズを計算します。例えば、`memory_align(10, 4)` の場合、サイズ10のメモリを4バイトのアライメントに調整するために必要なサイズを返します。
*/
/*
ビットAND演算には、メモリアライメントの調整など、さまざまな場面でメリットがあります。以下に、ビットAND演算の主なメリットをいくつか挙げます。

1. アライメントの強制: メモリアライメントは、特定のデータ型やハードウェアアーキテクチャに依存する場合があります。ビットAND演算を使用してアライメントマスクを適用することで、特定のアライメント要件を強制することができます。これにより、データの配置が最適化され、パフォーマンスが向上する場合があります。

2. メモリの境界チェック: ビットAND演算は、特定のビットパターンをマスクする効果があります。メモリの境界チェックに使用する場合、マスクされたビット以外のビットはすべてゼロになります。これにより、メモリの境界を超えるアクセスや無効なメモリアクセスを検出することができます。

3. ビット操作: ビットAND演算は、特定のビットパターンを抽出したり、特定のビットをクリアしたりするために使用できます。ビットマスクを作成することで、特定のビット操作を効率的に実行することができます。

4. メモリ節約: ビットAND演算は、メモリ使用量を最適化するのに役立ちます。不要なビットをクリアすることで、メモリの使用量を削減できます。特に大量のデータを扱う場合や、メモリ制約のある環境では、メモリ節約が重要な要素となります。

これらのメリットにより、ビットAND演算は、メモリ操作やデータ操作の最適化、パフォーマンスの向上、メモリ節約などのさまざまな用途で広く使用されています。
*/
/*

`const`（定数）修飾子にはいくつかのメリットがあります。

1. 変更の防止: `const` 修飾子を変数や関数の前に付けることで、その値を変更できないようにします。これにより、意図しない変更やバグを防ぐことができます。プログラムの他の部分で誤って値を変更することがなくなるため、コードの安全性が向上します。

2. コンパイラ最適化のサポート: `const` 修飾子を使用することで、コンパイラに対して値が変更されないことを伝えることができます。これにより、コンパイラはより積極的な最適化を行うことができます。例えば、コンパイル時に定数の値を直接埋め込むことで、実行時のオーバーヘッドを削減することができます。

3. ドキュメントとしての役割: `const` 修飾子は、コードを読む他の開発者に対して、変数や関数が変更されないことを明示的に示す役割も果たします。コードの可読性を向上させ、コードの意図や振る舞いをより明確に伝えることができます。

4. 定数の表現: `const` 修飾子を使用して定数を定義することができます。定数はプログラムの中で何度も使用される値を表現するために便利です。例えば、数学的な定数や、特定のデータ型の上限・下限値などが定数として定義されることがあります。

5. メモリ使用量の最適化: `const` 修飾子は、メモリの最適化にも役立ちます。コンパイラは、定数値をプログラムの実行時にメモリに割り当てるのではなく、コード内に直接埋め込むことができます。これにより、メモリ使用量を削減することができます。

これらのメリットにより、`const` 修飾子はコードの安全性、可読性、最適化、メモリ効率などの側面で重要な役割を果たします。適切に使用することで、より堅牢なコードを記述することができます。
*/

/*
`size_t` 型にはいくつかのメリットがあります。

1. プラットフォームの依存性の回避: `size_t` 型は、メモリ領域やオブジェクトのサイズを表すために使用される整数型です。この型は、プラットフォームの依存性を回避するために標準化されています。つまり、異なるプラットフォームやコンパイラでも一貫性のある結果を得ることができます。そのため、ポータブルなコードを記述する際に便利です。

2. メモリサイズの表現: `size_t` 型は、メモリ領域やオブジェクトのサイズを表現するために最適な型です。これは、メモリ領域のアドレスやオブジェクトのサイズを扱う場面で頻繁に使用されます。例えば、配列の要素数やバッファのサイズを表現するのに適しています。

3. メモリ操作関数との互換性: `size_t` 型は、C言語の標準ライブラリや多くの関数インターフェースで使用されています。`malloc`、`memcpy`、`strlen` など、メモリ操作関数は `size_t` 型を引数や戻り値として受け取ることが一般的です。そのため、`size_t` 型を使用することで、これらの関数との互換性を保つことができます。

4. 符号なし整数型: `size_t` 型は符号なし整数型であり、負の値を表現しません。これは、メモリやデータのサイズを表す際に適しています。符号なし整数型を使用することで、オーバーフローや負の値に関連する問題を回避することができます。

5. 数学的演算の適用: `size_t` 型は、整数の性質に基づいて数学的な演算が適用できます。加算、減算、乗算、比較演算など、一般的な数学的操作を `size_t` 型に対して行うことができます。

これらのメリットにより、`size_t` 型はメモリやデータのサイズを表現するために便利な型となっています。特に、ポータブルなコードの記述やメモリ操作関数との互換性の確保、数学的な操作の適用など、メモリサイズに関連する処理で広く使用されています。
*/
};

struct StackAllocator
{


	void* Allocate(size_t size, size_t alignment);
	void  Deallocate(void* pointer);
	uint8_t* memory;
	size_t                       total_size = 0;
	size_t                       allocated_size = 0;

};