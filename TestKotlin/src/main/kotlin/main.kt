import java.io.File
import java.io.IOError

fun main() {
    readFile("D:/text.txt")
    writeFile("D:/text.txt")
}

fun readFile(dir: String) {
    try {
        val file = File(dir)
        val text = file.readText()
        print(text)
    } catch (error: IOError) {
        error.printStackTrace()
    }
}

fun writeFile(dir: String) {
    try {
        val text = "YYY"
        val file = File(dir)
        file.writeText(file.readText() + text)
    } catch (error: IOError) {
        error.printStackTrace()
    }
}
