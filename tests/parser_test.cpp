#include <catch.hpp>
#include <parser/parser.hpp>

class ParserTester
{
public:
    ParserTester() : parser_{}
    {
        using namespace std::placeholders;

        parser_.set_callback(std::bind(&ParserTester::set_int, this, _1));
        parser_.set_strcallback(std::bind(&ParserTester::set_intstr, this, _1));
    }

    void run(const char *msg) { parser_.parse(msg); }
    void set_int(int n) { value_ = n; }
    void set_intstr(IntStr n) { value_ = n.value; }
    int get() const { return value_; }

private:
    Parser parser_;
    int value_;
};


TEST_CASE("Callback(int)", "[callback-int]")
{
    ParserTester t{};
    t.run("20");

    REQUIRE(t.get() == 20);
}

TEST_CASE("StrCallback(int)", "[callback-str]")
{
    ParserTester t{};
    t.run("i20");

    REQUIRE(t.get() == 20);
}
