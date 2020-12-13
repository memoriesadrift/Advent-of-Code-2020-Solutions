def checkRoute (fileName, speedRight, speedDown)
  field = Array.new()
  File.foreach(fileName) { |line| field << line.chomp.split("")  }

  treeCount = 0;

  field.each_with_index do |elem, i|
    next unless i%speedDown == 0 || i == (field.size) - 1
    elem = elem.rotate(speedRight*(i/speedDown))
    treeCount += 1 if elem[0] == "#"
  end
  return treeCount
end

file = "input.txt"

puts "Tree Count (1,1): #{checkRoute(file, 1, 1)}"
puts "Tree Count (3,1): #{checkRoute(file, 3, 1)}"
puts "Tree Count (5,1): #{checkRoute(file, 5, 1)}"
puts "Tree Count (7,1): #{checkRoute(file, 7, 1)}"
puts "Tree Count (1,2): #{checkRoute(file, 1, 2)}"
puts checkRoute(file, 1, 1) *checkRoute(file, 3, 1) *checkRoute(file, 5, 1) *checkRoute(file, 7, 1) *checkRoute(file, 1, 2) 
