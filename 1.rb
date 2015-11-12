%x(./myCompiler.out -g #{ARGV[1]}.dot #{ARGV[1]}.c > #{ARGV[1]}.txt)
%x(chmod 777 #{ARGV[1]}.dot)
%x(dot -Tps -o #{ARGV[1]}.ps #{ARGV[1]}.dot)

