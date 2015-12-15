#include "XercesAction.h"
#include <iostream>
#include <string>

#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/framework/MemBufInputSource.hpp>
XERCES_CPP_NAMESPACE_USE
using namespace std;

XercesAction::XercesAction(void)
{
}

XercesAction::~XercesAction(void)
{
}

void XercesAction::ParseXmlFile()
{
    try {
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Error during initialization! :\n"
             << message << "\n";
        XMLString::release(&message);
        return;
    }

    XercesDOMParser* parser = new XercesDOMParser();
    parser->setValidationScheme(XercesDOMParser::Val_Always);
    parser->setDoNamespaces(true);    // optional

    ErrorHandler* errHandler = (ErrorHandler*) new HandlerBase();
    parser->setErrorHandler(errHandler);

    const char* xmlFile = "tests/Subnet/Default.xml";

    try {
        parser->parse(xmlFile);
    }
    catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Exception message is: \n"
             << message << "\n";
        XMLString::release(&message);
        return;
    }
    catch (const DOMException& toCatch) {
        char* message = XMLString::transcode(toCatch.msg);
        cout << "Exception message is: \n"
             << message << "\n";
        XMLString::release(&message);
        return;
    }
    catch (...) {
        cout << "Unexpected Exception \n" ;
        return;
    }

    delete parser;
    delete errHandler;
}

void XercesAction::PrintDOMNode(void* node)
{
    if (node == NULL)
        return;

    DOMNode* dNode = (DOMNode*)node;
    DOMNode* child;
    
    if (dNode->getNodeType() == DOMNode::ELEMENT_NODE)
    {
        char* name = XMLString::transcode(dNode->getNodeName());
        char* value = XMLString::transcode(dNode->getNodeValue());
        cout << "<" << name << ">" << endl;
        
        // Parse children
        for (child = dNode->getFirstChild(); child != NULL; child=child->getNextSibling()) 
        {
            PrintDOMNode(child);
        }

        cout << "</" << name << ">" << endl;

        XMLString::release(&name);
        XMLString::release(&value);
    }

}

void XercesAction::ParseXmlFromMemory()
{
    string strXml = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\
                    <Subnet>\
                    <IPRange>192.168.1.2~192.168.1.254</IPRange>\
                    <Netmask>255.255.255.0</Netmask>\
                    </Subnet>";
    
    try {
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Error during initialization! :\n"
             << message << "\n";
        XMLString::release(&message);
        return;
    }

    XercesDOMParser* parser = new XercesDOMParser();
    parser->setValidationScheme(XercesDOMParser::Val_Always);
    parser->setDoNamespaces(true);    // optional

    ErrorHandler* errHandler = (ErrorHandler*) new HandlerBase();
    parser->setErrorHandler(errHandler);

    const char * XML_STREAM_BUF_ID = "XML Streaming Buffer";
    MemBufInputSource* mem = new MemBufInputSource(
        (const XMLByte*)strXml.c_str(),  strXml.length(), 
        XML_STREAM_BUF_ID);

    try {
        parser->parse(*mem);
    }
    catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Exception message is: \n"
             << message << "\n";
        XMLString::release(&message);
        return;
    }
    catch (const DOMException& toCatch) {
        char* message = XMLString::transcode(toCatch.msg);
        cout << "Exception message is: \n"
             << message << "\n";
        XMLString::release(&message);
        return;
    }
    catch (...) {
        cout << "Unexpected Exception \n" ;
        return;
    }

    DOMDocument *xmlDoc = parser->getDocument();
    void* node = xmlDoc->getDocumentElement();
    PrintDOMNode(node);

    delete mem;
    delete parser;
    delete errHandler;
}


void XercesAction::Action()
{
    ParseXmlFile();

    ParseXmlFromMemory();
}
