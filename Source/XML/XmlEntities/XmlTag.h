#ifndef XML_TAG_H
#define XML_TAG_H

#include <iostream>
#include <string_view>
#include "..\XmlEntity.h"

using namespace std;

namespace XML
{
    enum class XmlTagType : uint8_t
    {
        Definition,     // <?xml version="1.1" encoding="UTF-8" ?>
        DocType,        // <!DOCTYPE greeting SYSTEM "hello.dtd">
        ProcInstr,      // <?xml-stylesheet href="my-style.css"?>
        Comment,        // <!-- это комментарий -->
        Element,        // <element1> </element1> <empty_element1 />
        CDATA,          // 
        Reference       // 
    };

    class XmlTag : public XmlEntity
    {

    public:

        XmlTag(string_view content, XmlTagType type);

        XmlTagType GetTagType() const;

        virtual void PrintContent(int tabs) const = 0;

    private:

        XmlTagType tagType;

    };

}

#endif
