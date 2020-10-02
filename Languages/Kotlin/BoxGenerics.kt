fun main(args: Array<String>) {
    val toys = arrayListOf<String>("gundam", "puzzle", "robocop", "iron man")
    val taxes = arrayListOf<Int>(200, 300, 1200, 200)
    val misc = arrayListOf<Any>("blossom", 'R', "harmonica", 12.0, "Reski")

    val toysBox : Box<String> = Box(toys)
    val taxesBox : Box<Int> = Box(taxes)
    val miscBox : Box<Any> = Box(misc)

    println(toysBox.boxItem())
    println(taxesBox.boxItem())
    println(miscBox.boxItem())
}

class Box<T>(val list : List<T>) {
    fun boxItem() : List<T> {
        return list
    }
}