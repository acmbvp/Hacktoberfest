data class Contact(
    val name: String,
    val second_name: String
)

var contact1 = contact {
    name = "alzer"
    second_name = "lino"
}

fun main(args: Array<String>) {
    println(contact1)
}