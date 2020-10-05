# To be able to run this script you should have installed ruby
# To run it from your console go to the directory where the file is and type:
# ruby hello_world.rb

def say_hello_and_give_the_time_in_utc(your_name)
  puts "Hola #{your_name}, the time in UTC is #{Time.now.utc}"
end

your_name = "Ramiro Solis"
say_hello_and_give_the_time_in_utc(your_name)
