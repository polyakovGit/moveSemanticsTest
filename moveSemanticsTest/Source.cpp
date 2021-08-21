#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>

struct A
{
    A() = default;
    A(const std::string& name) : _name(name) {}
    A(const char* name) : _name(name) {}
    A(const A& ref)
    {
        //std::cout << "A(const A& ref)" << std::endl;
        _name = ref._name;
    }
    A& operator=(const A& ref)
    {
        //std::cout << "A& operator=(const A& ref)" << std::endl;
        _name = ref._name;
        return *this;
    }
    A(A&& ref) noexcept
    {
        //std::cout << "A(const A&& ref)" << std::endl;
        _name = std::move(ref._name);
    }
    A& operator=(A&& ref) noexcept
    {
        //std::cout << "A& operator=( A&& ref)" << std::endl;
        _name = std::move(ref._name);
        return *this;
    }

    std::string _name;

};

int main()
{
    std::vector<A> vec =
    {
        "k;jzxdxfjndfajk;bvmkl;adklm;dkl;m",
        "pzSJD'kfsngv;adojgn;aojngear;on",
        ";pksaMfkojnsg;'lkeng'eaoignea'oig",
        "ckjhbnlxkjdhbnlkzdjbnklnjbjnbjnbjnjnnjbjnkxcbknxcbnjkxc",
        "sdpfjgbosdjosidjgosigjdfiojsodijbsoijsoibijbjrjoiojbjbjiijrtijjrhjsjbisibjsijbjpsibsiojbosigbisobiosjbojisfg",
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
        "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
        "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
        "dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd",
        "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc",
        "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz",
        "vbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbsdddddddddddddddddddddddd",
        "asdfasdfasdfasdfasdfsadfsadfsadfsadfsadfsadfasdfasdfasdfasdfasdfsdfasdfa",
        "gdgdgdgdgdgdgdgdgdgdggdggdgdgdgdgduydgiuaysdfguasdyfguasdfuysadfgasduiyfgsafguysadfasugyf",
        "gaegarefahfwaiefhaiuoyhfairufhaiufhaeifuhrefiarhfiuhfiuahfiuahgierugheiuheulihafuhvaiuvvvvvvvavavavver",
        "k;jzxdxfjndfajk;bvmkl;adklm;dkl;m",
        "pzSJD'kfsngv;adojgn;aojngear;on",
        ";pksaMfkojnsg;'lkeng'eaoignea'oig",
        "ckjhbnlxkjdhbnlkzdjbnklnjbjnbjnbjnjnnjbjnkxcbknxcbnjkxc",
        "sdpfjgbosdjosidjgosigjdfiojsodijbsoijsoibijbjrjoiojbjbjiijrtijjrhjsjbisibjsijbjpsibsiojbosigbisobiosjbojisfg",
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
        "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
        "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
        "dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd",
        "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc",
        "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz",
        "vbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbsdddddddddddddddddddddddd",
        "asdfasdfasdfasdfasdfsadfsadfsadfsadfsadfsadfasdfasdfasdfasdfasdfsdfasdfa",
        "gdgdgdgdgdgdgdgdgdgdggdggdgdgdgdgduydgiuaysdfguasdyfguasdfuysadfgasduiyfgsafguysadfasugyf",
        "gaegarefahfwaiefhaiuoyhfairufhaiufhaeifuhrefiarhfiuhfiuahfiuahgierugheiuheulihafuhvaiuvvvvvvvavavavver",
        "k;jzxdxfjndfajk;bvmkl;adklm;dkl;m",
        "pzSJD'kfsngv;adojgn;aojngear;on",
        ";pksaMfkojnsg;'lkeng'eaoignea'oig",
        "ckjhbnlxkjdhbnlkzdjbnklnjbjnbjnbjnjnnjbjnkxcbknxcbnjkxc",
        "sdpfjgbosdjosidjgosigjdfiojsodijbsoijsoibijbjrjoiojbjbjiijrtijjrhjsjbisibjsijbjpsibsiojbosigbisobiosjbojisfg",
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
        "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
        "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
        "dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd",
        "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc",
        "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz",
        "vbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbsdddddddddddddddddddddddd",
        "asdfasdfasdfasdfasdfsadfsadfsadfsadfsadfsadfasdfasdfasdfasdfasdfsdfasdfa",
        "gdgdgdgdgdgdgdgdgdgdggdggdgdgdgdgduydgiuaysdfguasdyfguasdfuysadfgasduiyfgsafguysadfasugyf",
        "gaegarefahfwaiefhaiuoyhfairufhaiufhaeifuhrefiarhfiuhfiuahfiuahgierugheiuheulihafuhvaiuvvvvvvvavavavver",
        "k;jzxdxfjndfajk;bvmkl;adklm;dkl;m",
        "pzSJD'kfsngv;adojgn;aojngear;on",
        ";pksaMfkojnsg;'lkeng'eaoignea'oig",
        "ckjhbnlxkjdhbnlkzdjbnklnjbjnbjnbjnjnnjbjnkxcbknxcbnjkxc",
        "sdpfjgbosdjosidjgosigjdfiojsodijbsoijsoibijbjrjoiojbjbjiijrtijjrhjsjbisibjsijbjpsibsiojbosigbisobiosjbojisfg",
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
        "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
        "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
        "dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd",
        "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc",
        "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz",
        "vbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbsdddddddddddddddddddddddd",
        "asdfasdfasdfasdfasdfsadfsadfsadfsadfsadfsadfasdfasdfasdfasdfasdfsdfasdfa",
        "gdgdgdgdgdgdgdgdgdgdggdggdgdgdgdgduydgiuaysdfguasdyfguasdfuysadfgasduiyfgsafguysadfasugyf",
        "gaegarefahfwaiefhaiuoyhfairufhaiufhaeifuhrefiarhfiuhfiuahfiuahgierugheiuheulihafuhvaiuvvvvvvvavavavver",
    };


    auto start_time = std::chrono::high_resolution_clock::now();
    std::uint64_t count = 0;

    while (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start_time).count() < 60)
    {
        decltype(vec) tmp_vec = vec;
        while (!tmp_vec.empty())
        {
            tmp_vec.erase(tmp_vec.begin());
        }
        count++;
    }

    std::cout << count << std::endl;
    //copy 899722
    //move 3084160
    //release rebuild
    return 0;
}