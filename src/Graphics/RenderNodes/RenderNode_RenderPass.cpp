#include "Graphics/RenderNodes/RenderNode_RenderPass.h"
#include <iostream>

SceneObject_RenderPass::SceneObject_RenderPass(TRenderPass pass)
    : m_tRenderPass(pass)
{
    //nothing todo, only initializer list
}

SceneObject_RenderPass::TRenderPass SceneObject_RenderPass::getRenderState()
{
    return m_tRenderPass;
}

SceneObject_RenderPass::~SceneObject_RenderPass()
{

}

void SceneObject_RenderPass::Render(std::shared_ptr<TItlRenderInfo> pRenderInfo)
{
    //first, save current render state
    TRenderPass old_state =  static_cast<TRenderPass>(pRenderInfo->tCurrentRenderPass);

    //add (bitwise OR) renderstate of this object to render info
    pRenderInfo->tCurrentRenderPass = m_tRenderPass;

    //render children
    RenderNode::Render(pRenderInfo);

    //restore old renderstate
    pRenderInfo->tCurrentRenderPass = old_state;
}
