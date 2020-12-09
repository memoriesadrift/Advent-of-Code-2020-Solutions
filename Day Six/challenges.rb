def sumAnswers(fileName)
  @letters = {"a"=> 0, "b" => 0, "c" => 0, "d" => 0, "e" => 0, "f" => 0, "g" => 0, "h" => 0, "i" => 0, "j" => 0, "k" => 0, "l" => 0, "m" => 0, "n" => 0, "o" => 0, "p" => 0, "q" => 0, "r" => 0, "s" => 0, "t" => 0, "u" => 0, "v" => 0, "w" => 0, "x" => 0, "y" => 0, "z" => 0 }
=begin
  alphabet = "abcdefghijklmnopqrstuvxyz"
  @letters = {}
  alphabet.split('').each do |x|
    @letters.merge({x => 0})
  end
=end
  data = File.open(fileName).read
  output = 0

  data.each_line do |line|
    if(line.empty?)
      @letters.each do |index| 
        if(@letters[index] > 0)
          output += 1
        end
      end
    end
    line.each_char do |letter|
      @letters[letter] += 1
      puts("printing!")
    end
  end 
end

file = "input.in"
puts("Answer: #{sumAnswers(file)}")
