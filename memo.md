## 开发随记

### 2019年5月7日

当前的开发环境是 CLion + WSL 的配置。
不知道把开发日记放在项目目录是是不是个好的选择，但至少这让我有了更多写作的动力。

注意，在以下情况下，函数的参数前加`const`也是没有必要的：

```C
typedef struct _bar
{
    Foo foo; 
}* bar

void dosth(const bar b); 
```

Clang-Tidy会给出下列提示：

> Clang-Tidy: 'b' declared with a const-qualified typedef type; results in the type being 'struct _list *const' instead of 'const struct _list *'

直觉上`b`是一个（结构体的）指针，而作为指针传入参数本应当用`const`约束。但实际上，正如告警所说，`b`的类型并非直接展开为`const struct _bar *`,而是展开为`struct _bar *const`。

`Clang- Tidy`的文档中[描述](https://clang.llvm.org/extra/clang-tidy/checks/misc-misplaced-const.html)了这一告警产生的原因：

**const关键字限定的是dosth函数中的指针变量b，而非类型bar。所以，b是一个被限定为const的指针，指向一块bar类型的内存。**

而又因为`b`是作为参数复制而来，所以`const`就完全没有必要了。

### 2019年5月7日

我发现在写库函数的时候，增加元素的函数总是最不好写的。不是因为难以实现，而是因为（相对）难以测试。因此先把其他检测类的函数写好。 
