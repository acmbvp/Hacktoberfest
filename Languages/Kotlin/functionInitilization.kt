// main function
fun main() {
    val user = setUser("Rizky Nugraha Herliyanto", 19)
    println(user)

    printUser("Rizky Nugraha Herliyanto")
}

fun setUser(name: String, age: Int) = "Your name is $name, and you $age years old"

fun printUser(name: String) {
    println("Your name is $name")
}