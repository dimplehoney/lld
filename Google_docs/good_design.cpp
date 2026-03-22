#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class DocumentElements
{
    public:
        virtual string render()=0;
};

class TextElement:public DocumentElements
{
    private:
        string text;
    public:
        TextElement (string text)
        {
            this->text=text;
        }

        string render() override
        {
            return text;
        }
};

class ImageElement:public DocumentElements
{
    private:
        string imagePath;
    public:
        ImageElement(string imagePath)
        {
            this->imagePath=imagePath;
        }

        string render() override
        {
            return "[Image : "+ imagePath + "]";
        }
};

class NewLineElement : public DocumentElements{
    public:
        string render()
        {
            return "\n";
        }

};

class TabSpaceElement : public DocumentElements{
    public:
        string render()
        {
            return "\t";
        }

};

class Document
{
    private:
        vector<DocumentElements*> documentElements;
    public:
        void addElement(DocumentElements* element)
        {
            documentElements.push_back(element);
        }

        string render()
        {
            string res;
            for(auto &it : documentElements)
            {
                res+=it->render();
            }
            return res;
        }
};

class Persistence
{
    public:
        virtual void save(string data)=0;
};

class saveToFile : public Persistence
{
    public:
        void save(string data)
        {
            ofstream outFile("document.txt");
            if (outFile)
            {
                outFile << data;
                outFile.close();
                cout << "document saved to document.txt" << endl;
            }
            else
            {
                cout << "unable to open file for writing" << endl;
            }
        }
};

class saveToDB : public Persistence
{
    public:
        void save(string data)
        {
            cout << "saved to DB" << endl;
        }
};

class DocumentEditor 
{
    private:
        Document* document;
        Persistence* storage;
        string renderedDocument;

    public:
        DocumentEditor(Document* document, Persistence* storage)
        {
            this->document=document;
            this->storage=storage;
        }

        void addText(string text)
        {
            document->addElement(new TextElement(text));
        }

        void addImage(string imagePath)
        {
            document->addElement(new ImageElement(imagePath));
        }

        void addNewLine()
        {
            document->addElement(new NewLineElement());
        }

        void addTabSpace()
        {
            document->addElement(new TabSpaceElement());
        }

        string renderDocument()
        {
            if(renderedDocument.empty())
            {
                renderedDocument=document->render();
            }

            return renderedDocument;
        }

        void saveDocument()
        {
            storage->save(renderDocument());
        }

};


int main()
{
    Document* document=new Document();
    Persistence* persistence=new saveToFile();

    DocumentEditor* editor=new DocumentEditor(document, persistence);

    editor->addText("Hello World");
    editor->addNewLine();
    editor->addText("this is a document editor example");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("this is indented text after tab space");
    editor->addNewLine();
    editor->addImage("picture.jpg");

    cout << editor->renderDocument() << endl;

    editor->saveDocument();
}



